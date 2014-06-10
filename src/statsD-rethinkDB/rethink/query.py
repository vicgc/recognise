import os
import rethinkdb as r

RDB_HOST =  os.environ.get('RDB_HOST') or 'localhost'
RDB_PORT = os.environ.get('RDB_PORT') or 28015
LINK_DB = 'Recognise'

conn = r.connect(host=RDB_HOST, port=RDB_PORT, db=LINK_DB)

res = r.table('Students').get(1).run(conn)

#print res

res = r.table('Students').filter({ 'classes_missed': 0}).pluck('mobileNO',
                                                               'studentsID', 'email').run(conn)

for i in res:
    print i

