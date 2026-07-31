# 🚗 Smart GPS Route Planner with AI-Based Traffic Prediction

 

**Smart GPS Route Planner with AI-Based Traffic Prediction** is a C++ console-based navigation system that simulates the core functionality of modern GPS applications. The project uses **Data Structures and Algorithms (DSA)** to model a road network as a weighted graph and employs **Dijkstra's Algorithm** to compute the shortest and most efficient routes between locations.

In addition to traditional shortest-path computation, the project integrates an **AI-inspired traffic prediction model** that estimates traffic congestion based on factors such as **time of day, day of the week, and road distance**. By dynamically adjusting travel times according to predicted traffic conditions, the system recommends the fastest route instead of simply selecting the shortest one.

The project demonstrates practical implementation of graph algorithms, object-oriented programming, priority queues, and heuristic-based traffic analysis, making it an excellent academic and portfolio project.

---

# 🎯 Objectives

*  Develop a graph-based GPS navigation system using C++.
*  Implement efficient shortest-path computation using Dijkstra's Algorithm.
*  Simulate AI-based traffic prediction for intelligent route planning.
*  Recommend optimal routes based on predicted congestion.
*  Demonstrate advanced Data Structures and Algorithms in a real-world application.
*  Build a scalable and modular navigation system using Object-Oriented Programming.

---

# ✨ Key Features

## 🗺️ Graph-Based Road Network

* 📍 Represents cities as graph vertices.
* 🛣️ Represents roads as weighted edges.
* 🔄 Supports bidirectional road connections.
* ➕ Dynamically creates the road network from user input.

## 🚀 Intelligent Route Planning

* 📍 Calculates the shortest route between two locations.
* ⚡ Uses Dijkstra's Algorithm with a priority queue.
* 🎯 Finds the minimum-distance path efficiently.

## 🤖 AI-Based Traffic Prediction

* 🕒 Predicts congestion using:

  * Current hour
  * Day of the week
  * Road distance
* 🚦 Dynamically adjusts travel time.
* 🚗 Recommends the fastest route instead of only the shortest route.

## 📊 Traffic Analysis

* 🟢 Low Traffic
* 🟡 Moderate Traffic
* 🟠 High Traffic
* 🔴 Severe Traffic

Additional Features:

* 📈 Calculates congestion percentage.
* ⏱️ Displays estimated travel time.
* 📍 Predicts traffic conditions before route selection.

## 🔄 Route Comparison

* 📏 Compare Shortest Distance Route
* ⚡ Compare Fastest AI Route
* ✅ Select the most efficient path based on traffic.

## 💻 Interactive Console Interface

* 🎮 Menu-driven navigation.
* ✍️ User-defined road network.
* 📍 Displays cities, roads, routes, distance, and ETA.

---

# 🛠️ Technologies Used

* 💻 C++
* 🧩 Object-Oriented Programming (OOP)
* 📚 Data Structures & Algorithms (DSA)
* 🌐 Graphs (Adjacency List)
* ⚖️ Weighted Graph
* ⚡ Priority Queue
* 📍 Dijkstra's Algorithm
* 🤖 AI-Inspired Traffic Prediction
* 📦 STL (Vector, Priority Queue, Unordered Map)

---

# 📂 Data Structures Used

## 🌐 Graph

Stores the complete road network.

## 🔗 Adjacency List

Efficiently stores neighboring cities and roads while minimizing memory usage.

## ⚡ Priority Queue (Min Heap)

Selects the next city having the minimum travel cost.

## 📋 Vector

Stores routes, distances, and adjacency lists.

## 🗂️ Unordered Map

Maps city names to unique IDs for fast lookup.

---

# 🧠 Algorithms Used

## 📍 Dijkstra's Algorithm

Computes the shortest route between two locations.

### ⏱️ Time Complexity

```text
O((V + E) log V)
```

Where:

* **V** = Number of Cities
* **E** = Number of Roads

Using a priority queue significantly improves performance for large road networks.

---

# 🤖 AI-Based Traffic Prediction

Instead of relying solely on static road distances, the system predicts traffic using a heuristic AI-inspired model.

### 📥 Input Factors

* 🕒 Current Hour
* 📅 Day of Week
* 🛣️ Road Distance
* 🚦 Congestion Multiplier

### 📌 Formula

```text
Predicted Travel Time =
Base Travel Time × Traffic Multiplier
```

### 📖 Example

✅ Normal Road

* Base Time = 20 min
* Traffic Multiplier = 1.0
* Estimated Time = 20 min

🚦 Rush Hour

* Base Time = 20 min
* Traffic Multiplier = 1.7
* Estimated Time = 34 min

This enables the GPS to recommend faster routes during heavy congestion.

---

# 🏗️ Project Architecture

## 📂 Graph Module

Responsible for:

* ➕ Adding cities
* 🛣️ Adding roads
* 🌐 Creating the graph
* 📍 Displaying road network

**Files**

* 📄 Graph.h
* 📄 Graph.cpp

---

## 🧭 GPS Module

Responsible for:

* 📍 Shortest Route
* ⚡ Fastest Route
* 🔄 Route Comparison
* 🗺️ Displaying Results

**Files**

* 📄 GPS.h
* 📄 GPS.cpp

---

## 🚦 Traffic Predictor Module

Responsible for:

* 🤖 Predicting Traffic
* 📈 Estimating Congestion
* ⏱️ Calculating Travel Time
* 🚥 Classifying Traffic Levels

**Files**

* 📄 TrafficPredictor.h
* 📄 TrafficPredictor.cpp

---

## 🖥️ Main Module

Responsible for:

* 🎮 User Interaction
* 📋 Menu System
* 📥 Reading Road Network
* 🚗 Calling GPS Services

**File**

* 📄 main.cpp

---

# 🔄 Project Workflow

1. 🏗️ User creates the road network.
2. 🌐 Graph stores all cities and roads.
3. 📍 User selects source and destination.
4. 🕒 User enters current time and day.
5. 🤖 Traffic predictor estimates congestion.
6. ⚡ Dijkstra's Algorithm computes the optimal route.
7. 🚗 GPS recommends the fastest route.
8. 📊 Distance, ETA, congestion, and traffic level are displayed.

---

# 📸 Sample Output

```text
Available Cities

A
B
C
D
E

Source : A
Destination : E

Current Hour : 18
Day : Friday

Recommended Route

A → C → D → E

Total Distance : 19 km
Estimated Time : 31.5 minutes
Traffic Level : Moderate
Congestion : 35%
```

---

# 🌟 Advantages

* ⚡ Fast route computation.
* 📈 Optimized graph algorithms.
* 🧩 Modular OOP design.
* 🔄 Dynamic user input.
* 🤖 AI-inspired traffic estimation.
* 📉 Efficient memory usage.
* 🚀 Highly scalable.
* 🎯 Optimized pathfinding using priority queues.

---

# 🚀 Future Enhancements

* 🌍 Google Maps API Integration
* ☁️ Real-Time Traffic API
* 🌦️ Weather-Based Traffic Prediction
* ⭐ A* Search Algorithm
* 🤖 Machine Learning Traffic Model
* 📍 Live GPS Tracking
* 🖥️ GUI Version
* 🎤 Voice Navigation
* 🛣️ Multiple Route Suggestions
* ⛽ Fuel Cost Estimation
* 🚧 Road Closure Detection
* 🗄️ Database Integration
* 📱 Android/iOS Application

---

# 📖 Learning Outcomes

* 📚 Graph Theory
* 🌐 Weighted Graphs
* ⚡ Dijkstra's Algorithm
* 🧩 Priority Queues
* 💻 Object-Oriented Programming
* 📦 STL Containers
* 🚗 Route Optimization
* 📈 Algorithm Analysis
* 🤖 AI-Inspired Decision Making
* 🏗️ Modular Software Design
* 💡 Problem Solving Using DSA

---

# 🎉 Conclusion

The **Smart GPS Route Planner with AI-Based Traffic Prediction** combines **Graph Theory, Dijkstra's Algorithm, Priority Queues, Object-Oriented Programming, and AI-inspired traffic analysis** to build an intelligent navigation system. By dynamically estimating traffic conditions and computing optimal routes, the project demonstrates practical applications of **DSA, C++, and algorithm optimization**, making it an excellent portfolio project for software engineering roles and technical interviews.
