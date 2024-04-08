#include <iostream>
#include <vector>
#include <queue>


using namespace std;


int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int count = 0;
    int not_want = 0;

    queue<int> student_q;
    queue<int> sandwich_q;
    for (int i = 0; i < students.size(); ++i) {
        student_q.push(students[i]);
    }

    for (int i = 0; i < sandwiches.size(); ++i) {
        sandwich_q.push(sandwiches[i]);
    } 

    while (1) {
        if (student_q.empty()) {
            break;
        }
        if (student_q.front() == sandwich_q.front()) {
            student_q.pop();
            sandwich_q.pop();
            count ++;
            not_want = 0;
            continue;
        }
        else {
            int student_front = student_q.front();
            student_q.pop();
            student_q.push(student_front);
            not_want ++;
            if (not_want == student_q.size()) {
                break;
            }
            continue;
            
        }
    }

    return (students.size() - count);

}