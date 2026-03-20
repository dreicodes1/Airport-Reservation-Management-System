Airport Reservation System (C Language)

Overview
  This is a **console-based Airport Reservation System** developed in C.  
  The program allows users to view available flights, reserve seats, apply discounts, and display reservation details.
 
Features
  - Display available flights with destinations and seat availability  
  - Reserve seats for selected flights  
  - Choose flight class (Economy, Business, First Class)  
  - Apply discounts:
    - 15% discount using promo code **AMBERGANDA**
    - 10% discount for reserving more than 5 seats  
  - Store and display passenger reservation details  
  - Input validation for user entries  

Technologies Used
- **C Programming Language**
- Standard Libraries:
  - `stdio.h`
  - `string.h`

Program Structure

Functions
  - `applyDiscount()`  
    Applies discount based on promo code or seat count  

  - `calculatePayment()`  
    Calculates total cost based on seats and price  

  - `displayFlights()`  
    Displays all available flights and pricing  

  - `reserveSeat()`  
    Handles booking, input validation, and promo code  

  - `displayReservation()`  
    Displays all saved reservations  
