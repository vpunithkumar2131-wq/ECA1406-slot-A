
#include <systemc.h>

SC_MODULE(counting_semaphore) {
    int sem;

    // Split into distinct thread methods or pass distinct parameters,
    // as registered threads in SystemC expect unique process functions.
    void task1() { run_task("Task 1"); }
    void task2() { run_task("Task 2"); }
    void task3() { run_task("Task 3"); }

    void run_task(const char* name) {
        while (true) {
            wait(1, SC_SEC);
            if (sem > 0) {
                sem--;
                cout << name << " Accessing Resource at "
                     << sc_time_stamp()
                     << " | Remaining slots: " << sem << endl;
                wait(2, SC_SEC);
                sem++;
            }
        }
    }

    SC_CTOR(counting_semaphore) {
        sem = 2; // Allow up to 2 concurrent tasks
        SC_THREAD(task1);
        SC_THREAD(task2);
        SC_THREAD(task3);
    }
};

int sc_main(int argc, char* argv[]) {
    counting_semaphore obj("Counting");
    sc_start(10, SC_SEC);
    return 0;
}

// Standard main entry point
int main(int argc, char* argv[]) {
    return sc_main(argc, argv);
}
