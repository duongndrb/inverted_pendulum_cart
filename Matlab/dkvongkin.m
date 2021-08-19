%trong luong cua xe(kg)
M = 0.5;
%trong luong cua con lac(kg)
m = 0.2;
%he so ma sat cua xe (N/m/sec)
b = 0.1;
%khoi luong moment quan tinh (kg.m2)
I = 0.006;
%gia toc trong truong
g = 9.8;
%chieu dai toi tam con lac
l = 0.5;
q = (M+m)*(I+m*l^2)-(m*l)^2;
s = tf('s');
P_pend = (m*l*s/q)/(s^3 + (b*(I + m*l^2))*s^2/q - ((M + m)*m*g*l)*s/q - b*m*g*l/q);

Kp = 100;
Ki = 28;
Kd = 12;
C = pid(Kp,Ki,Kd);
T = feedback(P_pend,C);
t=0:0.01:10;
impulse(T,t)
title({'Response of Pendulum Position to an Impulse Disturbance';'under PID Control: Kp = 1, Ki = 1, Kd = 1'});
