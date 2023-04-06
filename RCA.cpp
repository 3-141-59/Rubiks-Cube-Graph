#include <iostream>
#include <map>
#include <cmath>
#include <string>

//Main Graph class
class Graph {
    public:
        std::string cmdinput;
        std::string TempOverlapName;
        int rows = 0;
        int columns = 0;
        std::string **graph;
        std::string **graphOverlap;
        std::map<std::string, int> graphOverlapData;
        std::map<std::string, bool> modes = 
                            {{"plot", true},
                             {"locate", false}};
        std::string mode;
        
        
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
        void print() {
            for(int s=0;s<rows;s++) {
                for(int k=0;k<columns;k++) {
                    std::cout<<graph[s][k];
                }
                
                std::cout<<std::endl;
            }    
                
                
                
            //Print out second graph containing information here
                
                
        }
        void plot(int x, int y) {
            graph[x][y] = "X";
        }
        void initialize() {
            for(int f=0;f<columns;f++) {
                graph[rows/2][f] = "─";
            }
            for(int x=0;x<rows;x++) {
                graph[x][columns/2] = "│";
            } 
            graph[rows/2][columns/2] = "┼";
        }
        void create_overlap(std::string ol_name) { 
            graphOverlap = new std::string*[rows];            
            for(int a=0;a<rows;a++) {
                graphOverlap[a] = new std::string[columns];
                for(int e=0;e<columns;e++) {
                    graphOverlap[a][e] = " ";
                }
            }
            graphOverlapData[ol_name] = 0;
        }
        void list_OverlapData() {
            std::map<std::string, int>::iterator itr;
            for(itr = graphOverlapData.begin(); itr != graphOverlapData.end(); ++itr) {
                std::cout<<itr->first<<' '<<itr->second<<std::endl;
            }
        }
        void remove_graphOverlap(std::string& OverlaptoRemove) {
            graphOverlapData.erase(OverlaptoRemove);
        }
        void delete_graphOverlaps() {
            for(int n=0;n<rows;n++) {
                delete[] graphOverlap[n];
            }
            delete[] graphOverlap;
        }
        void record_graph() {
            std::cout<<"> [SET_MODE]"<<std::endl;
            std::cout<<"> ";
            std::cin>>mode;
        }
        void linear_equation_example() {
            for(int ve=rows-1;ve>=0;ve--) {
                int ox=rows-1-ve;
                graph[ve][ox+26] = '/';
            }
            print();
        }
        void list_modes() {
            std::map<std::string, bool>::iterator itr;
            for(itr = modes.begin();itr!=modes.end();++itr) {
                if(itr->second==false) {
                    std::cout<<itr->first<<" NOT ACTIVE"<<std::endl;
                } else if (itr->second==true) {
                    std::cout<<itr->first<<" ACTIVE"<<std::endl;
                }
            }    
        } 
        void set_mode() { //Technically this isn't constant (we aren't just going to set the mode once)
            
        }

        ~Graph() {
            for(int w=0;w<rows;w++) {
                delete[] graph[w]; 
            }
            delete[] graph;
        } 
};

class graphDashboard : public Graph {
        int graphDashRows=0;
        int graphDashColumns=0;
        std::string **graphDash;
        graphDashboard(int graphDashRows, int graphDashColumns) : Graph(rows, columns) {}
        DashInitialize(int graphDashRows, int graphDashColumns) {
            graphDash = new std::string*[graphDashRows];
            for(int as=0;as<graphDashRows;as++) {
                graphDash[as]=new std::string[graphDashColumns];
                for(int sd=0;sd<graphDashColumns;sd++) {
                    graphDash[as][sd] = '?';
                }
            }
        }
        void Dashprint() {
            for(int fg=0;fg<graphDashRows;fg++) {
                for(int ju=0;ju<graphDashColumns;ju++) {
                    std::cout<<graphDash[fg][ju];
                }
                std::cout<<std::endl;
            }
        }
        //Use the function below for most cases of printing the graph
        void printGraphDashBoard() {
            for(int za=0;za<rows;za++) {
                print();
                std::cout<<"    ";
                Dashprint();
                std::cout<<std::endl;
            }
        }
};


int main() {
    //First, we declare the object with parameters that contain the size of the graph
    Graph RCA(50, 100);
    RCA.initialize(); 
    //Then, we find out what mode we want to go into (can be changed)
    RCA.record_graph(); //Ask once during recording of the data

    //Now we have most of the variables we need initialized, we can start to run an infinite loop
    //for commands, we may have nested while(true) as we have  various modes and certain commands
    //that will not be avalible in certain modes.
    //
    //mode locked commands:
    //  - plot
    //  - locate
    //
    //generic commands:
    //  - list_modes
    //  - print (graph)
    //  - create_overlap
    //
    //we are going to put the generic commands in the first while loop and
    //put all the mode locked ones in a nested while loop
 
    while(true) {
        std::cout<<"> ";
        std::cin>>RCA.cmdinput;
        if(RCA.cmdinput=="list_modes" || RCA.cmdinput=="lm") {
            RCA.list_modes();
        } else if (RCA.cmdinput=="create_overlap" || RCA.cmdinput=="co" ) {
            std::cin>>RCA.TempOverlapName;
            RCA.create_overlap(RCA.TempOverlapName);
        } else if (RCA.cmdinput=="list_overlapdata" || RCA.cmdinput=="lod") {
            RCA.list_OverlapData();
        } else if (RCA.cmdinput=="remove_graphoverlap" || RCA.cmdinput=="rgo") {
            std::cin>>RCA.TempOverlapName;
            RCA.remove_graphOverlap(RCA.TempOverlapName);    
        } else if (RCA.cmdinput=="print" || RCA.cmdinput=="p") {
            RCA.print();
        } else if (RCA.cmdinput=="exit") {
            break;
        } else if (RCA.cmdinput=="linear_example" || RCA.cmdinput=="le") {
            std::system("clear");
            RCA.linear_equation_example();
            std::cout<<"y=x"<<std::endl;
        } else if (RCA.cmdinput=="clearconsole" || RCA.cmdinput=="cc") {
            std::system("clear");
            RCA.print();
        }
    }
    return 0;
}
