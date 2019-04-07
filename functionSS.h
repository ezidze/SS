#ifndef functionSS
#define functionSS

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

#define N 400
#define MM 400000
#define step (unsigned)int(MM / 3.0)
#define delta_t 1.0e-6
#define delta_m double( 1.0 / N )
#define gamma 5.0 / 3.0

#define T0 3500.0                               
#define E0 3.15 * 10e9                         
#define ro0 5.45 * 10e-4                        
#define P0 1.15 * 10e6                          
#define V0 1.0 / ro0

#define Rx 100.0                                
#define Ux 5.6 * 10e4                           
#define tx 0.847*10e-3                        
#define rox (1 / 3.0 * ro0)
#define mx (rox * (Rx ** 3) / 3.0)
#define Px ((1.0 / 3) * ro0 * E0)
#define Ex 3.15 * 10e9

double u[N + 1];
double P[N + 1];
double Rho[N + 1];
double E[N + 1];
double r[N + 1];
double V[N + 1];

void start_values() {

	for (int i = 0; i < N + 1; i++) {

		u[i] = 0.0;

	}

	for (int i = 1; i < N + 1; i++) {

		r[0] = 0.0;

		r[i] = pow(( pow(r[i - 1], 3) + delta_m ), 1.0 / 3.0);

	}

	//for (int i = 0; i < N + 1; i++) { cout << r[i] << " " << i << endl; }

	//system("pause");

	for (int i = 0; i <= N + 1; i++) {


		Rho[i] = 3.0;

		V[i] = 1.0 / Rho[i];

	}

	for (int i = 0; i <= N + 1; i++) {

		P[i] = Rho[i] * (gamma - 1.0);

	}

	for (int i = 0; i <= N + 1; i++) {

		E[i] = 1.0;

	}
			
}

double u_function( double u, double P1, double P2, double r) {

	return u - delta_t / delta_m * pow(r, 2) * (P1 - P2);

}

double r_function(double r, double u) {

	return r + u * delta_t;

}

double P_function(double E, double V) {

	return (gamma - 1.0) * E / V;

}

double E_function(double E, double V1, double V2) {

	return E * V2 / V1 * (V1 + (gamma - 1.0) / 2.0 * (V1 - V2)) / (V2 - (gamma - 1.0) / 2.0 * (V1 - V2));
}

double V_function(double r1, double r2) {

	return (pow(r1, 3) - pow(r2, 3)) / 3.0 / delta_m;
}

#endif