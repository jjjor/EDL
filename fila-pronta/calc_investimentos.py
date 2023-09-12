from functions import get_values, choices


def table():
    options = {
        "1": "Mensal",
        "2": "Anual",
    }

    print("Bem-vindo à calculadora de investimento!")
    choices()

    choice = input("Digite o tipo da duração do investimento: ")
    selected_option = options.get(choice, "opção inválida")

    if selected_option == "Mensal":
        timeOrPeriod = int(input("Digite a quantidade de meses: "))
        [amount, totalInvested, totalIncome] = get_values(
            timeOrPeriod, "monthly")

    else:
        timeOrPeriod = int(input("Digite a quantidade de anos: "))
        [amount, totalInvested, totalIncome] = get_values(
            timeOrPeriod, "yearly")

    print("RESULTADO DOS INVESTIMENTOS:")
    print("-" * 40)
    print("| {:<20} | {:<13} |".format("Descrição", "Valor"))
    print("-" * 40)
    print("| {:<20} | {:<13.2f} |".format("Montante final", float(amount)))
    print("| {:<20} | {:<13.2f} |".format(
        "Total Investido", float(totalInvested)))
    print("| {:<20} | {:<13.2f} |".format(
        "Rendimento Total", float(totalIncome)))
    print("-" * 40)


if __name__ == "__main__":
    table()