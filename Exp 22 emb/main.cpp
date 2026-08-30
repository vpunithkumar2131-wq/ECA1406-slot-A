#define SC_MAIN_FUNC
#include <systemc.h>

SC_MODULE(ClockExample) {
    sc_in<bool> clk;

    void process() {
        while (true) {
            wait();
            std::cout << "Time: " << sc_time_stamp()
                      << " - Clock Triggered" << std::endl;
        }
    }

    SC_CTOR(ClockExample) {
        SC_THREAD(process);
        sensitive << clk.pos();
    }
};

int sc_main(int argc, char* argv[]) {
    sc_clock clock("clock", 1, SC_NS);
    ClockExample module("module");
    module.clk(clock);
    sc_start(5, SC_NS);
    return 0;
}

// Add this at the very bottom of main.cpp:
int main(int argc, char* argv[]) {
    return sc_main(argc, argv);
}
