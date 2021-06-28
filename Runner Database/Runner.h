class Runner {
public:
    string name; // athlete's name
    int time;    // athlete's time
    Runner (string name = "no name", int time = 0) {
        this->name = name;  this->time = time;
    }
    void print() { cout << name << "\t" << time << endl; }
};  ///
