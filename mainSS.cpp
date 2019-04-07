#include <iostream>
#include <cmath>
#include <fstream>
#include "functionSS.h"

using namespace std;

int main() {

	ofstream out_ichi;
	ofstream out_ni;
	ofstream out_san;
	
	out_ichi.open("first_out.txt");
	out_ni.open("second_out.txt");
	out_san.open("third_out.txt");

	int i = 0;
	int graph_number = 0;
	start_values();

	while( r[N] < 100.0 ){

		i = i + 1;
		
		//cout << r[N] << " " << i << endl;

		u[N] = u_function(u[N], 0.0, P[N - 1], r[N]);

		for (int j = 0; j < N; j++) {

			if (j < N - 1) {

				u[j + 1] = u_function(u[j + 1], P[j + 1], P[ j ], r[j + 1]);

			}

				r[j + 1] = r_function(r[j + 1], u[j + 1]);

				double V_old = V[j];

				V[j] = V_function(r[j + 1], r[j]);

				E[j] = E_function(E[j], V_old, V[j]);

				P[j] = P_function(E[j], V[j]);

			//cout << u[j] << V[j] << E[j] << P[j] << endl;


			}

		//cout << r[N] << "\n";

		if (i % step == 0) {

			graph_number++;

			//cout << r[N] << graph_number << endl;

			for (int k = 0; k < N + 1; k++) {

				if (graph_number == 1) {

					out_ichi << u[k] << " " << 1.0 / V[k] << " " << E[k] << " " << r[k] << endl;

				}

				if (graph_number == 2) {

					out_ni << u[k] << " " << 1.0 / V[k] << " " << E[k] << " " << r[k] << endl;

				}

				if (graph_number == 3) {

					out_san << u[k] << " " << 1.0 / V[k] << " " << E[k] << " " << r[k] << endl;

				}

			}

		}
				
	}

	out_ichi.close();
	out_ni.close();
	out_san.close();
	
	

	//system("pause");

	return 0;

	
}