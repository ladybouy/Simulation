#!/usr/bin/env python3

import matplotlib.pyplot as plt
import pandas as pd
import sys
import seaborn as sns

def PlotTrajectory(aDataframe):
    time = aDataframe['Time_sec'].tolist()
    downrange = aDataframe['Down_Range_m'].tolist()
    crossrange = aDataframe['Cross_Range_m'].tolist()
    altitude = aDataframe['Altitude_m'].tolist()
    
    sns.set_theme()
    fig, ( ax1, ax2, ax3 ) = plt.subplots(3, 1)
    fig.suptitle("Ballistic Trajectory")
    fig.tight_layout()
    ax1.plot(downrange, altitude)
    ax1.set_xlabel("Down Range (m)")
    ax1.set_ylabel("Altitude (m)")
    ax1.set_title("Altitude vs Down Range")
    ax1.grid(True)
    ax2.plot(crossrange, altitude)
    ax2.set_xlabel("Cross Range (m)")
    ax2.set_ylabel("Altitude (m)")
    ax2.set_title("Altitude vs Cross Range")
    ax2.grid(True)
    ax3.plot(downrange, crossrange)
    ax3.set_xlabel("Down Range (m)")
    ax3.set_ylabel("Cross Range (m)")
    ax3.set_title("Down Range vs Cross Range") 
    ax3.grid(True)

    fig2 = plt.figure()
    ax4 = fig2.add_subplot(projection='3d')
    ax4.scatter(downrange, crossrange, altitude)
    plt.show()

def ReadCSVToDataFrame(aCSVfile):
    df = pd.read_csv(aCSVfile)
    return df

if __name__ == "__main__":
    csvFile = sys.argv[1];
    df = ReadCSVToDataFrame(csvFile)
    PlotTrajectory(df);
