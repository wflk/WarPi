RESOURCE_METHODS = ['GET', 'POST']
ITEM_METHODS = ['GET', 'PATCH', 'PUT']

MONGO_HOST = 'localhost'
MONGO_PORT = 27017

MONGO_DBNAME = 'WarPi'

gps_schema = {}  # TODO Cerberus grammar
aps_schema = {}  # TODO

DOMAIN = {
    'gps': gps_schema,
    'aps': aps_schema
}
