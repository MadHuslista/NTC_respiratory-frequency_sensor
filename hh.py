#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 10 05:34:22 2019

@author: meyerhof
"""

import matplotlib.pyplot as plt
import numpy as np
import dft
plt.close("all")

# Learn about API authentication here: https://plot.ly/python/getting-started
# Find your api_key here: https://plot.ly/settings/api

Fs = 1200.0;  # sampling rate
Ts = 1/Fs; # sampling interval
#t = np.arange(0,1,Ts) # time vector
t = np.linspace(0,1,1200)

ff_1 = 5;
ff_2 = 53;
ff_3 = 34;   # frequency of the signal
y = np.sin(2*np.pi*ff_1*t) + np.sin(2*np.pi*ff_2*t) + np.sin(2*np.pi*ff_3*t)

n = len(y) # length of the signal
k = np.arange(n)

T = n/Fs
#frq_1 = k/T # two sides frequency range
frq_1 = k*Fs/n
frq = frq_1[range(int(n/2))] # one side frequency range

Y_1 = dft.dft(y) # fft computing and normalization
Y_1 = np.array(Y_1)
Y = Y_1[range(int(n/2))]

fig, ax = plt.subplots(2, 1)
ax[0].plot(t,y)
ax[0].set_xlabel('Time')
ax[0].set_ylabel('Amplitude')
ax[1].plot(frq,abs(Y),'r') # plotting the spectrum
ax[1].set_xlabel('Freq (Hz)')
ax[1].set_ylabel('|Y(freq)|')
