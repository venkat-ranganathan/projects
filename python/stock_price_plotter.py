import yfinance as yf
import pandas as pd
import matplotlib.pyplot as plt


def get_stock_data(ticker, start_date, end_date):
    stock_data = yf.download(ticker, start=start_date, end=end_date)
    return stock_data


def plot_stock_data(stock_data):
    plt.plot(stock_data['Close'])
    plt.xlabel('Date')
    plt.ylabel('Price')
    plt.title('Stock Price Over Time')
    plt.show()


def save_stock_data(stock_data):
    stock_data.to_csv('stock_data.csv')


def main():
    ticker = input("Enter the stock ticker: ")
    start_date = input("Enter the start date (YYYY-MM-DD): ")
    end_date = input("Enter the end date (YYYY-MM-DD): ")

    stock_data = get_stock_data(ticker, start_date, end_date)

    plot_stock_data(stock_data)

    save_stock_data(stock_data)


if __name__ == '__main__':
    main()
