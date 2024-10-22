# Stock Trading Web Application

This is a comprehensive web-based stock trading application that allows users to manage their portfolios, make stock transactions, and view real-time stock prices. The application leverages **Flask** as the backend framework, uses **SQLite** for database management, and integrates with external APIs to fetch live stock quotes. It offers a user-friendly interface where individuals can register, log in, buy/sell stocks, and track their portfolio and transaction history.

## Features

### 1. **User Authentication**
- **Register**: Users can create a new account by providing a username, password, and initial cash balance.
- **Login/Logout**: Existing users can log in to access their portfolio. They can also securely log out at any time.

### 2. **Buying Stocks**
- Users can search for stocks by their symbol (e.g., AAPL for Apple) using the **Quote Lookup** feature, which fetches the latest stock price from a third-party API.
- After searching, users can enter the number of shares they want to buy. If they have sufficient funds, the transaction is processed and their portfolio is updated accordingly.
- A confirmation page displays the details of the transaction (stock symbol, shares purchased, and total cost).

### 3. **Selling Stocks**
- Users can sell stocks that they already own from their portfolio.
- The application shows the available shares for each stock, allowing the user to input how many shares they wish to sell.
- Once the transaction is confirmed, the cash balance and portfolio are updated.

### 4. **Transaction History**
- Users can view a complete history of all stock transactions (buy and sell) that they have made.
- Each entry in the transaction history includes:
  - Date and time of the transaction.
  - Stock symbol, number of shares, and price at which they were bought or sold.
  - The total cost of the transaction.

### 5. **Quote Lookup**
- Users can enter the stock symbol of any company to fetch the real-time stock price.
- This feature can be used to check the price before deciding whether to buy or sell a stock.

### 6. **Password and Account Management**
- Users can change their passwords after logging in for enhanced security.
- The application allows users to add additional funds to their account if they run low on cash for making purchases.

## Installation

1. **Clone the repository**:
    ```bash
    git clone <repository-url>
    cd finance
    ```

2. **Install dependencies**:
    ```bash
    pip install -r requirements.txt
    ```

3. **Initialize the database**:
    - Open the SQLite shell:
      ```bash
      sqlite3 finance.db
      ```
    - Create the database schema:
      ```bash
      .schema
      ```

4. **Start the Flask server**:
    ```bash
    flask run
    ```

5. **Access the application**:
    - Open a web browser and go to `http://127.0.0.1:5000/` to interact with the application.

## Usage

- **Register**: Navigate to the Register page and sign up by entering a unique username, password, and initial cash deposit.
- **Login**: Enter your credentials (username and password) to log in to your account.
- **Buy Stocks**: Navigate to the "Buy" page, enter the stock symbol, check the stock price, and purchase shares if desired.
- **Sell Stocks**: Navigate to the "Sell" page to sell shares from your portfolio.
- **View Transaction History**: Review past buy/sell transactions in detail.

## Project Structure

The project files are organized as follows:

- **app.py**: The main Flask application that handles routing and logic.
- **templates/**: Contains the HTML files for rendering the web pages.
  - `layout.html`: The base template for the application.
  - `register.html`, `login.html`, `buy.html`, `sell.html`: Pages for user interaction.
- **static/**: Stores static files such as CSS, JavaScript, and images.
- **finance.db**: The SQLite database file storing user data, stock transactions, and portfolio information.
- **helpers.py**: A helper file that contains utility functions for looking up stock prices, validating input, and interacting with the database.

## Personal Touch

- **Add Cash**: Users have the ability to increase their cash balance to make more purchases.

## Acknowledgments

This project was heavily inspired by the **CS50 Finance Problem Set**, with several enhancements made for a more personalized and feature-rich experience.
