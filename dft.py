#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 10 04:02:17 2019

@author: meyerhof
"""

import numpy as np 
import scipy as sp
import matplotlib.pyplot as plt 

plt.close("all")

times = np.linspace(0,10,200)

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
    C = C[range(rng)]
    
    return C

dft_sign = dft(points_3)
dft_sign = np.array(dft_sign)
w = np.arange(len(dft_sign)*2)

frq = w * 10/len(dft_sign)
frq = np.array(frq)
i = int(len(dft_sign))

#dft_sign_half = dft_sign[range(i)]
frq_half = frq[range(i)]

plt.plot(frq_half, abs(dft_sign))
        