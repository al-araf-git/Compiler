#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define EPSILON 26  // epsilon symbol index

// ===== Transition Table =====
int q[MAX][27][MAX];    // state -> symbol -> next states
int q_count[MAX][27];   // number of next states per state+symbol
int state = 1;          // state counter

// ===== NFA fragment =====
typedef struct {
    int start;
    int end;
} NFA;

NFA stack[MAX];
int top = -1;

void push(NFA n) { stack[++top] = n; }
NFA pop() { return stack[top--]; }

// ===== Transition Helper =====
void addTransition(int from, int sym, int to) {
    q[from][sym][q_count[from][sym]++] = to;
}

// ===== Thompson's Construction =====
void symbolNFA(char c) {
    NFA n;
    n.start = state++;
    n.end = state++;
    int sym = (c == 'e') ? EPSILON : (c - 'a');
    addTransition(n.start, sym, n.end);
    push(n);
}

void concatNFA() {
    NFA n2 = pop();
    NFA n1 = pop();
    addTransition(n1.end, EPSILON, n2.start);
    NFA n = { n1.start, n2.end };
    push(n);
}

void unionNFA() {
    NFA n2 = pop();
    NFA n1 = pop();
    NFA n;
    n.start = state++;
    n.end = state++;
    addTransition(n.start, EPSILON, n1.start);
    addTransition(n.start, EPSILON, n2.start);
    addTransition(n1.end, EPSILON, n.end);
    addTransition(n2.end, EPSILON, n.end);
    push(n);
}

void starNFA() {
    NFA n1 = pop();
    NFA n;
    n.start = state++;
    n.end = state++;
    addTransition(n.start, EPSILON, n1.start);
    addTransition(n.start, EPSILON, n.end);
    addTransition(n1.end, EPSILON, n1.start);
    addTransition(n1.end, EPSILON, n.end);
    push(n);
}

// ===== Operator precedence =====
int precedence(char c) {
    if (c == '*') return 3;
    if (c == '.') return 2;
    if (c == '|') return 1;
    return 0;
}

// ===== Convert regex to postfix =====
void toPostfix(char *infix, char *postfix) {
    char stack[100]; int top = -1, k = 0;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isalpha(c) || c == 'e') {
            postfix[k++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(')
                postfix[k++] = stack[top--];
            top--; // pop '('
        } else { // operator
            while (top >= 0 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = stack[top--];
            stack[++top] = c;
        }
    }
    while (top >= 0) postfix[k++] = stack[top--];
    postfix[k] = '\0';
}

// ===== Build NFA from postfix =====
void buildNFA(char *postfix) {
    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];
        if (isalpha(c) || c == 'e')
            symbolNFA(c);
        else if (c == '.')
            concatNFA();
        else if (c == '|')
            unionNFA();
        else if (c == '*')
            starNFA();
    }
}

// ===== Print Transition Table =====
void printTransitions(int nStates) {
    printf("\n\tTransition Table \n");
    printf("_____________________________________\n");
    printf("Current State |\tInput |\tNext State(s)\n");
    printf("_____________________________________\n");
    for (int i = 1; i <= nStates; i++) {
        for (int s = 0; s < 27; s++) {
            if (q_count[i][s] > 0) {
                char symbol = (s == EPSILON ? 'e' : 'a' + s);
                printf("\n q[%d]\t | %c | ", i, symbol);
                for (int k = 0; k < q_count[i][s]; k++)
                    printf("q[%d] ", q[i][s][k]);
            }
        }
    }
    printf("\n_____________________________________\n");
}

// ===== Main =====
int main() {
    char regex[100], temp[200], postfix[200];

    printf("Enter Regular Expression: ");
    scanf("%s", regex);

    // Insert explicit concatenation operator "."
    int k = 0;
    for (int i = 0; regex[i]; i++) {
        temp[k++] = regex[i];
        if ((isalpha(regex[i]) || regex[i] == ')' || regex[i] == '*') &&
            (isalpha(regex[i+1]) || regex[i+1] == '('))
            temp[k++] = '.';
    }
    temp[k] = '\0';

    // Convert to postfix
    toPostfix(temp, postfix);
    printf("Postfix: %s\n", postfix);

    // Build NFA
    buildNFA(postfix);
    NFA finalNFA = pop();

    // Print transitions
    printTransitions(state - 1);
    printf("Start State: q[%d]\n", finalNFA.start);
    printf("Final State: q[%d]\n", finalNFA.end);

    return 0;
}
