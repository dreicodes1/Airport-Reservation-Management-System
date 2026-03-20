#include <stdio.h>
#include <string.h>

float applyDiscount(float totalAmount, int seatCount, int codeCheck){
	if(codeCheck == 1){
		totalAmount = totalAmount * 0.85;
    }else if(seatCount > 5){
		totalAmount = totalAmount * 0.90;
    }
    
	return totalAmount;
}

float calculatePayment(int seatCount, float basePrice){
	return basePrice * seatCount;
}

void displayReservation(char firstN[][30], char lastN[][30], char gender[][30], int flightChosen[], int classChosen[],
int seatResNo[],int pCount, char flightNo[][30], char destination[][30], float discountedPrice[]){
	if(pCount <= 0){
		printf("No reservations yet. Input first.\n");
	}else{
	printf("=================================\n");
	printf("RESERVATION DETAILS\n");
	for(int i = 0 ; i < pCount ; i++){
		printf("=================================\n");
		printf("Passenger %d info:\n", i + 1);
		printf("Name: %s %s\n", firstN[i], lastN[i]);
		printf("Gender: %s\n", gender[i]);
		printf("Flight number and destination: %s - %s\n", flightNo[flightChosen[i] - 1], destination[flightChosen[i] - 1]);
		switch(classChosen[i]){
		case 1:
			printf("Reserved seats and class: %d Economy class seats\n", seatResNo[i]);
		break;
		case 2:
			printf("Reserved seats and class: %d Business class seats\n", seatResNo[i]);
		break;
		case 3:
			printf("Reserved seats and class: %d First class seats\n", seatResNo[i]);
		break;
		}
		printf("Total payment: %.2lf\n", discountedPrice[i]);
	}
	}

}

void reserveSeat(int pCount, int flightChosen[], int classChosen[], int seatResNo[], int availableSeats[],
char firstN[][10], char lastN[][10], char gender[][10], char email[][10], int phoneNo[], int promoCheck[]){
	printf("\nChoose Flight Number\n");
	printf("1 - CL001\n2 - CL002\n3 - CL003\n4 - CL004\n5 - CL005\n");
	printf("Enter here(1-5): ");
	scanf("%d", &flightChosen[pCount]);
	
	while(flightChosen[pCount] > 5 || flightChosen[pCount] < 1){
		printf("Flight doesn't Exist.\n");
		printf("Enter Again(1-5): ");
		scanf("%d", &flightChosen[pCount]);
	}
	
	while(availableSeats[flightChosen[pCount] - 1] <= 0){
		printf("There are no more available seats on your flight.\n");
		printf("Go somewhere else: ");
		scanf("%d", &flightChosen[pCount]);
	}
	
	printf("Your preferred flight class\n");
	printf("1 - Economy\n2 - Business\n3 - First\n");
	printf("Enter here: ");
	scanf("%d", &classChosen[pCount]);
	
	while(classChosen[pCount] > 3 || classChosen[pCount] < 1){
		printf("Class doesn't Exist.\n");
		printf("Enter Again(1-3): ");
		scanf("%d", &classChosen[pCount]);
	}

	printf("Seats available in chosen flight: %d\n", availableSeats[flightChosen[pCount] - 1]);
	printf("How many seats to reserve?: ");
	scanf("%d", &seatResNo[pCount]);
	
	while(availableSeats[flightChosen[pCount] - 1] < seatResNo[pCount]){
		printf("Not enough seats available.\n");
		printf("Reserve less seats: ");
		scanf("%d", &seatResNo[pCount]);
	}
	
	while(seatResNo[pCount] <= 0){
		printf("Invalid. Try Again.\n");
		printf("Reserve atleast 1 seat: ");
		scanf("%d", &seatResNo[pCount]);
	}

	availableSeats[flightChosen[pCount] - 1] = availableSeats[flightChosen[pCount] - 1] - seatResNo[pCount];

	char promoCode[1][15] = {"AMBERGANDA"};
	char codeInput[1][15];

	printf("Enter promo code *AMBERGANDA* for discount: ");
	scanf("%s", &codeInput[0]);
	if(strcmp(codeInput[0], promoCode[0]) == 0){
    	promoCheck[pCount] = 1;
	} else {
    	promoCheck[pCount] = 0;
	}

	printf("\n---Personal Information---\n");
	printf("Enter your First name: ");
	scanf("%s", &firstN[pCount]);

	printf("Enter your Last name: ");
	scanf("%s", &lastN[pCount]);

	printf("Enter your Gender: ");
	scanf("%s", &gender[pCount]);

	printf("Enter your Email: ");
	scanf("%s", &email[pCount]);

	printf("Enter your Phone no.: ");
	scanf("%d", &phoneNo[pCount]);

}

void displayFlights(int availableSeats[]){

	printf("\nFLIGHT NO.     DESTINATION     SEATS    ECONOMY	      BUSINESS	     FIRSTCLASS\n");
	printf("CL001	       Tokyo		%d	5500	      9000	     13000\n",availableSeats[0]);
	printf("CL002	       Seoul		%d	6000	      10000	     15000\n",availableSeats[1]);
	printf("CL003	       Singapore	%d	4800	      8500  	     12500\n",availableSeats[2]);
	printf("CL004	       Bangkok		%d	4300	      7900	     11000\n",availableSeats[3]);
	printf("CL005	       Dubai		%d	7500	      12000	     17000\n",availableSeats[4]);
}

int main(){

	char flightNo[5][10] = {"CL001","CL002","CL003","CL004","CL005"};
	char destination[5][20] = {"Tokyo", "Seoul", "Singapore", "Bangkok", "Dubai"};
	int availableSeats[5] = {25, 20, 30, 15, 20};
	float economyPrice[5] = {5500, 6000, 4800, 4300, 7500};
	float businessPrice[5] = {9000, 10000, 8500, 7900, 12000};
	float firstClassPrice[5] = {13000, 15000, 12500, 11000, 17000};

	char firstN[55][30];
	char lastN[55][30];
	char gender[55][30];
	char email[55][30];
	int phoneNo[55];
	int flightChosen[55];
	int seatResNo[55];
	int classChosen[55];

	float discountedPrice[55];

	int pCount = 0;
	int promoCheck[55] = {0};
	int choice = 0;

	printf("=================================\n");
	printf("   AIRPORT RESERVATION SYSTEM\n");
	do{
	printf("=================================\n");
	printf("1. Display Available Flights\n");
	printf("2. Reserve a Seat\n");
	printf("3. View Reservation Details\n");
	printf("4. Exit\n");

	printf("Enter your choice: ");
	scanf("%d", &choice);

	while(choice > 4 || choice < 1){
		printf("Choice doesn't exist. Choose again: ");
		scanf("%d", &choice);
	}

    switch (choice){
	case 1:
	    displayFlights(availableSeats);
	break;
	case 2:
	    reserveSeat(pCount, flightChosen, classChosen, seatResNo, availableSeats,
			firstN, lastN, gender, email, phoneNo, promoCheck);
		float basePrice;
		switch(classChosen[pCount]){
			case 1:
				basePrice = economyPrice[flightChosen[pCount] - 1];
			break;
			case 2:
				basePrice = businessPrice[flightChosen[pCount] - 1];
			break;
			case 3:
				basePrice = firstClassPrice[flightChosen[pCount]  - 1];
			break;
		}
		basePrice = calculatePayment(seatResNo[pCount], basePrice);
		discountedPrice[pCount] = applyDiscount(basePrice, seatResNo[pCount], promoCheck[pCount]);

		printf("=================================\n");
		printf("Calculated payment...\n");
	printf("Total before discount: %.2f\n", basePrice);

	if(promoCheck[pCount] == 1){
		printf("Promo applied 15 percent off from entering code *AMBERGANDA*!\n");
	}else if(seatResNo[pCount] > 5){
		printf("Promo applied 10 percent off from reserving more than 5 seats!\n");
	}else{
		printf("No discounts was made\n");
	}
	printf("Final Amount: %.2f\n", discountedPrice[pCount]);

		pCount++;
	break;
	case 3:
	    displayReservation(firstN, lastN, gender, flightChosen, classChosen, seatResNo, pCount, flightNo, destination, discountedPrice);
	break;
    }

}while(choice != 4);
	printf("Thankyou for using our AIRPORT RESETRVATION SYSTEM!\n");
	printf("RATE US!\n");

	return 0;
}