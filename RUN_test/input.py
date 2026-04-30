

trick.var_server_set_port(49152)
trick.var_server_set_enabled(1)

trick.real_time_enable()
trick.exec_set_software_frame(0.1)

dr = trick.DRAscii("ball")
dr.add_variable("ball_sim.ball.dPosition")
dr.add_variable("ball_sim.ball.dVelocity")
dr.set_freq(trick.DR_Always)
trick.add_data_record_group(dr)

ball_sim.ball.dPosition = 50.0
ball_sim.ball.dVelocity = 0.0
ball_sim.ball.dGravity = 9.81
ball_sim.ball.dBounce = 0.8

trick.stop(10.0) # time in sec
