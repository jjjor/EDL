def get_values(period, type):
    valueInit = float(input("Digite o valor inicial: "))
    monthlyDeposit = float(input("Digite o valor do depósito mensal: "))
    interestRate = float(input("Digite o valor da taxa de juros: "))

    if type == "yearly":
        monthlyInterestRate = ((1 + interestRate / 100) ** (1 / 12)) - 1
        [amount, totalInvested, totalIncome] = calcAmount(
            valueInit, period * 12, monthlyInterestRate, monthlyDeposit
        )

    else:
        # INTEREST RATE MONTHLY
        monthlyInterestRate = interestRate / 100
        [amount, totalInvested, totalIncome] = calcAmount(
            valueInit, period, monthlyInterestRate, monthlyDeposit
        )

    formattedAmount = f"{amount}"

    return [formattedAmount, totalInvested, totalIncome]


def choices():
    print("-" * 40)
    print("Escolha uma opção:")
    print("1 - Mensal")
    print("2 - Anual")


def calcAmount(valueInit, period, interestRate, monthlyDeposit):
    amount = valueInit
    totalInvested = valueInit
    print("-" * 50)
    print("| {:<4} | {:<15} | {:<18} |".format("Mês", "Montante/mês", "Rendimento/mês"))
    print("-" * 50)

    totalIncome = 0

    for i in range(period):
        totalInvested += monthlyDeposit
        monthlyIncome = amount * interestRate
        totalIncome += monthlyIncome
        amount = amount * (1 + interestRate)
        amount += monthlyDeposit
        print(
            "| {:<4} | {:<15.2f} | {:<18.2f} |".format(
                i + 1, amount, amount - monthlyIncome
            )
        )
        print("-" * 50)

    return [amount, totalInvested, totalIncome]