# imports
import socket
import matplotlib.pyplot as plt
import numpy as np
import subprocess
import time


# run sim
sim = subprocess.Popen(
        ['./S_main_Linux_13.3_x86_64.exe', 'RUN_test/input.py'],
        cwd='../')
time.sleep(1) # give sim time to fully start up

# main loop
try:
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(("localhost", 49152))
    print("connection successful")

    # create file-like interface for readline
    insock = sock.makefile("r")

    # get tics per second once before subscribing to variables
    sock.send(b'trick.var_pause()\n')
    sock.send(b'trick.var_add("trick_sys.sched.time_tic_value")\n')
    sock.send(b'trick.var_send()\n')
    line = insock.readline()
    parts = line.split("\t")
    tics_per_second = int(parts[1])
    sock.send(b'trick.var_clear()\n')

    # add variables
    sock.send(b'trick.var_add("trick_sys.sched.time_tics")\n')  # sim time
    sock.send(b'trick.var_add("ball_sim.ball.dPosition")\n')    # ball position

    # setup
    sock.send(b'trick.var_cycle(0.1)\n')  # server tick rate
    sock.send(b'trick.var_unpause()\n')   # start data stream

    # matplotlib setup
    plt.figure()
    times = []
    positions = []

    # loop and listen
    while True:
        line = insock.readline()
        if not line:
            print("connection closed")
            break

        # parse data
        parts = line.split("\t")
        if len(parts) < 3:
            continue

        # convert time tics to seconds
        simTime = float(int(parts[1]) / tics_per_second)
        ballPosition = float(parts[2])

        # matplotlib
        plt.clf()
        plt.title("Ball Position")
        plt.xlabel("time (s)")
        plt.ylabel("position (m)")

        # update lists and plot
        times.append(simTime)
        positions.append(ballPosition)
        plt.plot(times, positions)
        plt.pause(0.01)

except ConnectionRefusedError:
    print("connection failed")
finally:
    try:
        sock.close()
        sim.terminate()
    except:
        pass