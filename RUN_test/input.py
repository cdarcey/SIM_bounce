

dr = trick.DRAscii("ball")
dr.add_variable("ball_sim.ball.dPosition")
dr.add_variable("ball_sim.ball.dVelocity")
dr.set_freq(trick.DR_Always)
trick.add_data_record_group(dr)

ball_sim.ball.dPosition = 500.0
ball_sim.ball.dVelocity = 0.0
ball_sim.ball.dGravity = 9.81
ball_sim.ball.dBounce = 0.8

trick.stop(10.0) # time in sec
