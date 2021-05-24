
#Projeto de CAL Entrega 2 - Vaccine Router
### João Afonso, Sérgio Estêvão, Rodrigo Tuna


##Descrição
Projeto baseado na criação, manipulação e visualização de grafos em ordem a resolver o Multi-Depot Vehicle Routing problem.

##Conteúdos

```cpp
~ algorithms/
    AStar.cpp
    AStar.h
    BiDijkstra.cpp
    BiDijkstra.h
    ClarkeWright.cpp
    ClarkeWright.h
    Dijkstra.cpp
    Dijkstra.h
    Kosaraju.cpp
    Kosaraju.h
    Tarjan.cpp
    Tarjan.h
~ graph/
      Edge.cpp
      Edge.h
      Graph.cpp
      Graph.h
      GraphReader.cpp
      GraphReader.h
      Node.cpp
      Node.h
+ lib/
~ maps/
      clients.txt :
	- N -> Número de clientes
	- idNode, Q -> id do Node, Demand do cliente

      depots.txt
	- N -> Número de depots
	- idNode -> id do Node

      porto_full_edges.txt
	- N -> Número de edges
	- (idNodeBegin, idNodeDest) -> id do Node de início e destino da edge, respetivamente

      porto_full_nodes_xy.txt
	- N -> Número de nodes
	- (idNode, xCord, yCord) -> id do Node, coordenada do x e coordenada do y, respetivamente

~ structures/
      POI.cpp
      POI.h
      Route.cpp
      Route.h
GraphDisplayer.cpp
GraphDisplayer.h
data.txt
    - maxTime -> tempo máximo de conservação de cada vacina no veículo (em horas)
    - maxQuantity -> número de vacinas que os veículos transportam
main.cpp
Manager.cpp
Manager.h
MenuInterface.cpp
MenuInterface.h
```

