# Raygame - steering project

This is a project that showcases the ability of steering behaviors
along with A-star and dijkstras search. It also incorperates finite
state machine and decision tree to show off there abilities.

This does use raylib to enhance its capabilites.

There are six sterring behaviors that the users should know of. They
are arrive, flee, evade, pursue, seek, and wander. Each one of them is similar
in how they are coded with wander being the most different one. Arrive allows the AI
to slow down as it approaches the target. Flee makes it so they will flee from the
position that is marked. Evade does the same thing while incorperating a
position stat to allow for smarter evading. Pursue will continue to follow and not
stop until it is on top of the location. Seek will also follow until it is on top the
location, but also intergrates position for smarter detection. Wander is where the AI
will have a line of sight that it will just wander around with.

Finite State Machine is an agent, (a more organized actor class), which can implement
actions that the AI will be able to do. They are simple but important action.
Examples include walking, running, ducking, and jumping.

Dijkstra's search is a engine that searches for a dot planted on a map.
It uses g-score to calculate the amount of time it would take to get
to the destination in the shortest time. G-score is the time cost of 
going to a different node.

A-star search is like dijkstra's, but it doesn't use g-acore. It uses 
f-score or final score to calculate the fastest way to get to the 
destination. Final score uses g-score and heuristic to get the score.
Heuristic is the distance formula or Manhattan distance formula. The 
second one allows for more accurate measurements.

Decision tree is a decision making strategy that can be used instead
of finite state machine. They use yes or no questions to come to a quick
answer. The questions are know as branches and the answers are leaves.
The only downside is you can only use yes or no questions which limits
the questions you can use.

These are all the classes implemented into Raygame.
