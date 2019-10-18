#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 16 22:22:53 2019

@author: meyerhof
"""

import numpy as np 
import matplotlib.pyplot as plt
#import dft

plt.close("all")

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
    
    
    
    C = np.array(C)
    
    
    return C

def wind (signal):
    wr = list(signal)
    c0 = 0.355768
    c1 = 0.487396
    c2 = 0.144232
    c3 = 0.012604
    L = len(wr)
    wbhn = []
    for t in range(len(wr)):
        wr_t = wr[t]
        
        suma1 = c0*np.cos((2*np.pi*0*t)/L) - c1*np.cos((2*np.pi*1*t)/L)
        suma2 = c2*np.cos((2*np.pi*2*t)/L) - c3*np.cos((2*np.pi*3*t)/L)
        suma = suma1 + suma2
        
        wbhn_t = wr_t*suma
        
        wbhn.append(wbhn_t)
        
    
    return wbhn

def noise(signal, Anoise=1):
    z = list(signal)
    white_noise = 2*np.random.rand(len(z), 1) -1    #Aquí el np.random.rand() genera ruido aleatorio de distribución uniforme, entre [0,1]. Luego al multiplicar por 2, el rango queda en [0,2], y finalmente al restar en uno, queda [-1,1] => Conclusión: Ruido aleatorio entre -1 y 1
    for i in range(len(z)):
        z[i] = z[i] + Anoise*white_noise[i]
    return z


def dft_plot(points_3, color='tab:blue'):
    dft_sign = dft(points_3)
    dft_sign = np.array(dft_sign)
    w = np.arange(len(dft_sign))

    frq = w * f_sampl/samples
    frq = np.array(frq)
    i = int(len(dft_sign)/2)

    plt.plot(frq[range(i)], abs(dft_sign[range(i)]), color)
    return list(dft_sign)


def interpol(signal, tipo='g'): 
    if tipo == 'g': 
        for i in signal: 
            

t_recorded = 3     #Secs
f_sampl = 2         #Hz
samples = t_recorded*f_sampl
times = np.arange(0,t_recorded, (1/f_sampl))
t = np.linspace(1,t_recorded,f_sampl*t_recorded)


w_1 =  2*np.pi* 0.5
w_2 = 2*np.pi* 0.5
w_3 = 2*np.pi* 0.4
points_1 = np.sin(w_1*times)
points_2 = np.sin(w_2*times)
points_3 = np.sin(w_3*times)
DC = 3.3
sin = points_1 #+ points_2 + points_3 

noise_sin = noise(sin)
win = wind(noise_sin)

if 0: 
    plt.plot(sin)
    plt.plot(noise_sin, 'r')
    plt.plot(win, 'g')
else: 
    dft_sin =  dft_plot(sin,'+' )
    dft_ns =  dft_plot(noise_sin, 'r+')
    dft_win = dft_plot(win, 'g+')
