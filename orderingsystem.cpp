# Ordering-System
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace OrderSystem {
    struct Order {
        string itemName;
        double price;
        int quantity;
    };

    vector<Order> orders;

    void addOrder() {
        cout << "Choose a category to order from:\n";
        cout << "1. Steaks\n";
        cout << "2. Sea Foods\n";
        cout << "3. Appetizers\n";
        cout << "4. Wines\n";
        cout << "5. Fruit Drinks\n";
        cout << "6. Smoothies\n";
        cout << "Enter your choice: ";

        int categoryChoice;
        cin >> categoryChoice;

        if (categoryChoice < 1 || categoryChoice > 6) {
            cout << "Invalid category choice. Returning to main menu.\n";
            return;
        }

        vector<pair<string, double>> menu;

        if (categoryChoice == 1) {
            menu = {
                {"Wagyu Beef Steak", 22000},
                {"Tomahawk Steak", 5200},
                {"Filet Mignon", 2600},
                {"T-Bone Steak", 3400},
                {"Chateaubriand", 5700}
            };
        } else if (categoryChoice == 2) {
            menu = {
                {"Grilled Octopus", 2000},
                {"Lobster Thermidor", 5200},
                {"Oysters on the Half Shell", 500},
                {"Alaskan King Crab", 5600},
                {"Fish Tacos with Grilled Fish", 1200}
            };
        } else if (categoryChoice == 3) {
            menu = {
                {"Truffle Fries", 200},
                {"Crab Cakes", 200},
                {"Stuffed Mushrooms", 250},
                {"Foie Gras", 1500},
                {"Shrimp Cocktail", 400}
            };
        } else if (categoryChoice == 4) {
            menu = {
                {"Screaming Eagle Cabernet Sauvignon", 20000},
                {"Opus One", 15000},
                {"Châteauneuf-du-Pape", 10000},
                {"Tokaji Aszú", 5500},
                {"Sancerre", 6000}
            };
        } else if (categoryChoice == 5) {
            menu = {
                {"Freshly Squeezed Orange Juice", 300},
                {"Pineapple Ginger Juice", 550},
                {"Strawberry Basil Lemonade", 450},
                {"Lychee Martini", 500},
                {"Pomegranate Juice", 600}
            };
        } else if (categoryChoice == 6) {
            menu = {
                {"Acai Berry Smoothie", 400},
                {"Tropical Green Smoothie", 250},
                {"Mango Coconut Smoothie", 250},
                {"Chocolate Peanut Butter Banana Smoothie", 300},
                {"Matcha Green Tea Smoothie", 350}
            };
        }

        cout << "Choose an item to order:\n";
        for (size_t i = 0; i < menu.size(); ++i) {
            cout << i + 1 << ". " << menu[i].first << " - P" << menu[i].second << "\n";
        }
        cout << "Enter your choice: ";
        int itemChoice;
        cin >> itemChoice;

        if (itemChoice < 1 || itemChoice > menu.size()) {
            cout << "Invalid item choice. Returning to main menu.\n";
            return;
        }

        cout << "Enter quantity: ";
        int quantity;
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Invalid quantity. Returning to main menu.\n";
            return;
        }

        orders.push_back({menu[itemChoice - 1].first, menu[itemChoice - 1].second, quantity});
        cout << "Order added successfully!\n";
    }

    void editOrder() {
        if (orders.empty()) {
            cout << "No orders to edit.\n";
            return;
        }

        cout << "Edit Order:\n";
        for (size_t i = 0; i < orders.size(); ++i) {
            cout << i + 1 << ". " << orders[i].itemName << " - Quantity: " << orders[i].quantity << "\n";
        }

        cout << "Enter the order number to edit (or 0 to return to the menu): ";
        int choice;
        cin >> choice;

        if (choice == 0) return;

        if (choice < 1 || choice > orders.size()) {
            cout << "Invalid choice. Returning to menu.\n";
            return;
        }

        int index = choice - 1;

        cout << "1. Change Quantity\n";
        cout << "2. Remove Item\n";
        cout << "Enter your choice: ";
        int action;
        cin >> action;

        if (action == 1) {
            cout << "Enter new quantity: ";
            int newQuantity;
            cin >> newQuantity;
            if (newQuantity <= 0) {
                cout << "Invalid quantity. Returning to menu.\n";
                return;
            }
            orders[index].quantity = newQuantity;
            cout << "Quantity updated.\n";
        } else if (action == 2) {
            orders.erase(orders.begin() + index);
            cout << "Order removed.\n";
        } else {
            cout << "Invalid choice. Returning to menu.\n";
        }
    }

    void viewOrders() {
       if (orders.empty()) {
        cout << "No orders to display.\n";
    } else {
        cout << "\nCurrent Orders:\n";
        double totalPrice = 0.0;
        for (const auto &order : orders) {
            double itemTotal = order.price * order.quantity;
            totalPrice += itemTotal;
            cout << order.itemName << " - Quantity: " << order.quantity << " - Total: P" << itemTotal << "\n";
        }
        cout << "Grand Total: P" << totalPrice << "\n";
    }
    cout << "\nPress Enter to return to the main menu...\n";
    cin.ignore(); // Clear any remaining input buffer
    cin.get();    // Wait for user to press Enter
}


  void confirmOrder() {
    if (orders.empty()) {
        cout << "No orders to confirm.\n";
        return;
    }

    cout << "\nConfirm Your Order:\n";
    double totalPrice = 0.0;
    for (const auto &order : orders) {
        double itemTotal = order.price * order.quantity;
        totalPrice += itemTotal;
        cout << order.itemName << " - Quantity: " << order.quantity << " - Total: P" << itemTotal << "\n";
    }
    cout << "Grand Total: P" << totalPrice << "\n";

    cout << "Confirm order? (Y/N): ";
    char confirm;
    cin >> confirm;

    if (confirm == 'Y' || confirm == 'y') {
        cout << "\nPlease pay P" << totalPrice << " to confirm your order.\n";
        cout << "Enter amount paid: ";
        double payment;
        cin >> payment;

        if (payment >= totalPrice) {
            double change = payment - totalPrice;
            cout << "Payment successful! Change: P" << change << "\n";
            cout << "Order confirmed! Thank you for ordering.\n";
            orders.clear();

            // Ask if user wants to proceed with another order
            cout << "\nWould you like to place another order? (Y/N): ";
            char anotherOrder;
            cin >> anotherOrder;

            if (anotherOrder == 'Y' || anotherOrder == 'y') {
                cout << "Returning to the main menu...\n";
            } else {
                cout << "Thank you! Exiting...\n";
                exit(0); // Exit the program
            }

        } else {
            cout << "Insufficient payment. Order not confirmed.\n";
        }
    } else {
        cout << "Order not confirmed.\n";
    }
}



    void showMainMenu() {
    while (true) {
        cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
        cout << "Menu:\n\n";
        cout << "(1) Steaks:                                               (4) Wines:\n";
        cout << "Wagyu Beef Steak - P22000 per kilogram"  << "\t\t\t Screaming Eagle Cabernet Sauvignon - P20000 per bottle\n";
        cout << "Tomahawk Steak - P5200 per serving"      << "\t\t\t Opus One - P15000 per bottle\n";
        cout << "Filet Mignon - P2600 per serving"        << "\t\t\t Châteauneuf-du-Pape - P10000 per bottle\n";
        cout << "T-Bone Steak - P3400 per serving"        << "\t\t\t Tokaji Aszú - P5500 per bottle\n";
        cout << "Chateaubriand - P5700 per serving"       << "\t\t\t Sancerre - P6000 per bottle\n\n";
        cout << "(2) Sea Foods:                                            (5) Fruit Drinks:\n";
        cout << "Grilled Octopus - P2000 per serving"     << "\t\t         Freshly Squeezed Orange Juice - P300 per glass\n";
        cout << "Lobster Thermidor - P5200 per kilogram"   << "\t\t\t Pineapple Ginger Juice  - P550 per glass\n";
        cout << "Oysters on the Half Shell - P500 per serving" << "\t\t Strawberry Basil Lemonade - P450 per glass\n";
        cout << "Alaskan King Crab - P5600 per kilogram"   << "\t\t\t Lychee Martini - P500 per glass\n";
        cout << "Fish Tacos with Grilled Fish - P1200 per serving" << "\t\t Pomegranate Juice - P600 per glass\n\n";
        cout << "(3) Appetizers:                                           (6) Smoothies:\n";
        cout << "Truffle Fries - P200 per serving\t\t\t Acai Berry Smoothie - P400\n";
        cout << "Crab Cakes - P200 per piece\t\t\t\t Tropical Green Smoothie - P250\n";
        cout << "Stuffed Mushrooms - P250 per piece \t\t\t Mango Coconut Smoothie - P250\n";
        cout << "Foie Gras - P1500 per serving\t\t\t\t Chocolate Peanut Butter Banana Smoothie - P300\n";
        cout << "Shrimp Cocktail - P400 per piece\t\t\t Matcha Green Tea Smoothie - P350";
        cout << "\n----------------------------------------------------------------------------------------------------------------------\n";

        cout << "Options:\n";
        cout << "1. Add Order\n";
        cout << "2. View Orders\n";
        cout << "3. Edit Order\n";
        cout << "4. Confirm Order\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: addOrder(); break;
            case 2: viewOrders(); break;
            case 3: editOrder(); break;
            case 4: confirmOrder(); break;
            case 5: cout << "Exiting...\n"; return;
            default: cout << "Invalid option. Try again.\n"; break;
        }
    }
}

}

int main() {
    OrderSystem::showMainMenu();
    return 0;
}
