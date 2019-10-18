#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 10 04:02:17 2019

@author: meyerhof
"""

import numpy as np 
import scipy as sp
import matplotlib.pyplot as plt 

t_recorded = 10     #Secs
f_sampl = 200         #Hz

samples = t_recorded*f_sampl

times = np.arange(0,t_recorded, (1/f_sampl))

w_1 =  2*np.pi* 3
w_2 = 2*np.pi* 5
w_3 = 2*np.pi* 8
points_1 = 1023*np.sin(w_1*times)
points_2 = 1023*np.sin(w_2*times)
points_3 = points_2 + points_1 + 1023*np.sin(w_3*times)



def dft (x): 
    
    N = len(x)
    C = []
    
    for k in range(0, N):
        
        re = 0 
        im = 0
        
        for n in range (0, N):
            
            phi = (2*np.pi*k*n)/N
            
            re += x[n] * np.cos(phi) 
            im += x[n] * np.sin(phi) * -1
            
        
        re = re/N
        im = im/N
        
        amp = np.sqrt(re*re + im*im)
        
        C.append(complex(re,im))
    
    
    rng = int(N/2)
    C = np.array(C)
    
    
    return C

dft_sign = dft(points_3)
dft_sign = np.array(dft_sign)
w = np.arange(len(dft_sign))

frq = w * f_sampl/samples
frq = np.array(frq)
i = int(len(dft_sign)/2)

plt.plot(frq[range(i)], abs(dft_sign[range(i)]))
        