#include <bits/stdc++.h>

//Graph class
class Graph {
    public:
        int rows = 0;
        int columns = 0;
        std::string **graph;
        std::string **graphOverlap;
        std::map<std::string, int> graphOverlapData;
        
        Graph(int rows, int columns) : rows(rows), columns(columns) {
            graph = new std::string*[rows];
            for(int i=0;i<rows;i++) {
                graph[i] = new std::string[columns];
                for(int h=0;h<columns;h++) {
                  graph[i][h] = ' ';
                }
            }
            std::system("clear");
            std::cout<<"Initialization was succesfull"<<std::endl;
        }
        print() {
            for(int s=0;s<rows;s++) {
                for(int k=0;k<columns;k++) {
                    std::cout<<graph[s][k];
                } 
                std::cout<<std::endl;
            }
        }
        plot(int x, int y) {
            graph[x][y] = "X";
        }
        initialize() {
            for(int f=0;f<columns;f++) {
                graph[rows/2][f] = "─";
            }
            for(int x=0;x<rows;x++) {
                graph[x][columns/2] = "│";
            } 
            graph[rows/2][columns/2] = "┼";
        }
        create_overlap(std::string ol_name) { 
            graphOverlap = new std::string*[rows];            
            for(int a=0;a<rows;a++) {
                graphOverlap[a] = new std::string[columns];
                for(int e=0;e<columns;e++) {
                    graphOverlap[a][e] = " ";
                }
            }
            graphOverlapData[ol_name] = 1;
        }
        print_OverlapData() {
            std::map<std::string, int>::iterator itr;
            for(itr = graphOverlapData.begin(); itr != graphOverlapData.end(); ++itr) {
                std::cout<<itr->first<<' '<<itr->second<<std::endl;
            }
        }
        delete_graphOverlaps() {
            for(int n=0;n<rows;n++) {
                delete[] graphOverlap[n];
            }
            delete[] graphOverlap;
        }

        ~Graph() {
            for(int w=0;w<rows;w++) {
                delete[] graph[w]; 
            }
            delete[] graph;
        } 
};
int main() {
    //Objects
    Graph RCA(50, 100);
    
    //Graph methods
    RCA.initialize();
    RCA.print();

    //What mode to go into (plot, locate mode etc)
    std::string command; //input variable
    while (true) {
        std::cin>>command;
        if(command=="test") {
            std::cout<<"You ran the test command"<<std::endl;
        } else if(command=="OverlapData") {
            RCA.create_overlap("MyOverlap1");
            RCA.create_overlap("MyOverlap2");
            std::system("clear");
            RCA.print();
            RCA.print_OverlapData();
            RCA.delete_graphOverlaps();
        }
    }

    return 0;
}
