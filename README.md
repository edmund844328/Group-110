# Group-110

ENGG1340/COMP2113 group project

Chung Ngok Ting (3035375765)

Tsang Edmund Chiu Yat (3035667261)

Game name: 

Life of a Trader

General Overview:

A personal finance management simulator game that incorporates financial news, personal events and random models on investment returns.

Game Setting:

1.  Players can create a new account by entering a new username and starting age. Or they can retrieve an existing account by entering his/her username.

2.  Each new account comes with an initial capital of USD10,000.

3.  There will be ten U.S. company stocks (FB, AAPL, AMZN, NFLX, GOOG, AAL, QCOM, MMM, JPM, WMT) and 4 commodities (Bitcoin, HKD, Gold, Crude Oil) available for trading.

4.  User date (name, age, remaining capital) will be saved into a file after each trading week.

5.  For every 4 weeks, the player will receive a monthly salary of USD 2,000, which will increase, decrease or remain unchanged depending on some random events.

Game Procedures:

1.  Players set up their individual profiles first. Each profile represents one player.

2.  The in-game date starts from 1st Jan 2021, with each session lasting for a week.

3.  For each session, stocks or commodities will be evaluated at a different price, depending on financial news, volatility of individual stocks or commodities.

4.  For every 4 weeks, the player will receive a monthly salary of USD 2,000, which will increase, decrease or remain unchanged depending on some random event (like     getting promoted or fired).

5.  Players can trade on different stocks during each session. Players would trigger and end a session when they have completed all their desired trades.

6.  There will be some random life-events popping up during the course of the game (such as the need of buying a car, going on a vacation, getting into the hospital). For those events, they cost money and will deduct a certain amount of money from the account.

7.  The emergence of random life-events will be terminated if the player’s capital drops below a certain threshold, meaning the game will not deduct capital from the account until the player accumulates capital back to the threshold level. 

8.  Pursuant to the conditions in (7), the capital of the player would never drop below 0 (to lose), nor the game would end as capital accumulates to a certain amount (to win). In short, the game would continue in perpetuity.

9.  Players can save the progress at any given point in time.

10. Different players can compare the performance among them on a leaderboard, sorted according to the amount of remaining capital they have.

List of Features
1.  Randomness: All stock or commodity prices are random and would have different volatilities. All financial news and life events will also pop up randomly.

2.  Data Structures: Arrays, booleans, integer, double, char will be used depending on needs. Moreover, different files will be used to save player’s data.

3.  Dynamic memory management: The number of variables would be minimized, and if possible, store them onto a csv file for later usage instead of declaring and not using it.

4.  File input/output: Different profiles can be opened at wish. A text file is used to store the progress of a particular profile. A trade log is also available for viewing in case the user wishes to do so.

5.  Functions will be separated into different files for better understanding and allow simultaneous collaboration. Moreover, a “Makefile” file will be included for better and more effective compilation.
