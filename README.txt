# Ecommerce-Project
# Excersize 1

# Project created by:
Shahar Chalfon
ID: 204351845
Group: א
Proffessor: Keren Kalif

Lior Lapid
ID: 316266055
Group: א
Proffessor: Keren Kalif

# User Guide/Testing Clarifications
>>Introduction
Our E-Commerce system is designed as a user-based platform.
Meaning in order to use the program, you must sign-up/log-in to the system with a buyer/seller account.
In order to make our program more user-friendly, we included this user guide to help understand
our approach to an e-commerce system.

When first opening the program, a main menu will be presented with the following options:
- Log-in
- Sign-up
- View user lists
- Operator tests
- Exit
After selecting any of the first three options, you will be asked to select between buyer/seller

>>Operator tests
A menu will be presented on screen, with the following options:
- '<<'
- '+='
- '>'
- Return

The operator '<<' will present a menu of the following options:
- product
- date
- address
- feedback
- Return
Each option will create a temporary object of the corresponding class.
That object will be printed using the << operator and then deleted.

The operator '+=' will present a menu of the following options:
- buyer
- seller
- buyerseller
Each option will create a test user of the corresponding user type.
The created user will then be added to the system permanently.

The operator '>' will ask the user to pick 2 buyers/buyersellers that exist in the system.
If a buyer is not picked for any reason, you will be returned to the operator testing menu.
After a successful selection, their shopping cart values will be printed on screen.
And then those values will be compared, whilst the result is printed on screen.

>>Sign-up
In order to create a user, there are some prerequisites that you must follow as our program requires
correct inputs for all fields else the program will malfunction.
You will be asked to enter three fields for both buyers and sellers:
-Username:
Must contain 6-15 characters.
Cannot contain any symbol, space or non alphanumeric characters.
Example - buyer1
-Password:
Must contain 6-15 characters.
Must contain one of each of the following: a-z, A-Z and 0-9.
Cannot contain any symbol, space or non alphanumeric characters.
Example - Aa1234
-Address:
Street name, city and country can only contain a-z, A-Z, '-' and spaces.
Max length is 100, 30 and 30 respectively.
House number and zipcode can only contain numbers.
Max length is 1-3 and 7 digits respectively.
Example - Gazza 55, Tel-Aviv, Israel, 1234567

After the sign-up process, you will automatically be logged in.
If you only wish to create users without performing actions, simply log-out immediatly after
user creation.

>>User lists - Questions 8/9
In the main menu, selecting option 3 "View user lists" will ask you which list you wish to print.
After selecting buyer/seller, the respective list will be printed on screen.

>>Log-in
There are two user menus displayed, depending on the user type:
-Buyer Menu:
The following options will be displayed:
1. Add item to your shopping cart
2. Create new order
3. Pay for existing order
4. Publish a feedback
5. Charge wallet
6. Log-out

-Seller Menu:
1. Add product to store
2. Search for product by name
3. Log-out

The log out option in both menus, will return you to the main menu.
The rest of the options will be explained shortly.

>>Buyer Actions
1. Question 5 - Add item to your shopping cart
You will be asked to enter the name of the product you wish to add to your shopping cart.
A list of all existing products with that name will be printed.
You will be asked to select which of the printed products you wish to add using
the serial number printed below each product.
After entering the serial number, the product will be added to your shopping cart.

2. Question 6 - Create new order
Your shopping cart will be printed to the screen, and you will be asked to choose which products
to add to the new order using their index which will be presented to you.
After selecting each product, you will be given an option to select another or finsh the process.
After finishing, you will be returned to the buyer menu.
Only one order may exist at a time, therefore if an order exists, you will be asked if you wish to
cancel the existing order and return all items to your shopping cart, or cancel the attempt
to start a new order.

3. Question 7 - Pay for existing order
Your order will be printed to your screen, and you will be asked if you wish to pay.
If you havn't created an order, you will receive an error. 
If you have inssuficient funds in your wallet you will receive an error.

4. Question 4 - Publish a feedback
You must first purchase a product before attempting to publish a feedback.
Your order history will be printed on screen, order by order.
You will be asked to pick a product for which to publish a feedback or to move to the next order.
If you run out of orders, you will be returned to the buyer menu.
You may only post one feedback per item you purchased.
After selecting a product you will be asked to enter the following:
-Feedback Description:
Max length 250
-Date:
Must be in format: DD MM YYYY
Min year 2019, Max year 2020.
Must be valid date.
Your feedback will then be sent to tests to make sure you have not previously submitted a feedback
for the selected product.

5. Charge Wallet
In order to pay for orders you must have sufficient funds in your wallet.
There are no requirements for adding money.

>>Seller Actions
1. Question 3 - Add product to store
You will be asked to enter the following:
-Product name:
Can only contain alphanumeric characters and spaces.
-Product price
-Product category:
0=Kids, 1=Electrical, 2=Clothing and 3=Office.
A serial number will automatically be assigned to the new product.

2. Question 10 - Search for products by name
You will be asked to enter the name of the product you wish to search.
A list of all existing products with that name will be printed to your screen.