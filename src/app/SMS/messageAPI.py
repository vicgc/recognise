from AfricasTalkingGateway import AfricasTalkingGateway, AfricasTalkingGatewayException

import logging
logging.basicConfig(filename='SMS.log', level=logging.DEBUG)

username = "secret"
apikey = "secret"

# Please ensure you include the country code (+254 for Kenya in this case)
# to      = "+254724490814"; # kelvins number


def sendText(to, code):
    gateway = AfricasTalkingGateway(username, apikey)

    message = "Welcome to CarPool, a ride sharing plartform. Your User Code is %s " % (code)

    try:
        recipients = gateway.sendMessage(to, message)
        number = recipient['number']
        status = recipient['status']
        messageid = recipient['messageId']
        cost = recipient['cost']
        return status

    except AfricasTalkingGatewayException, e:
        logging.warning('Database setup completed %s' % str(e))
