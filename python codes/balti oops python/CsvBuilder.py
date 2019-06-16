
import csv

class CsvBuilder():
    def __init__(self,  horizontal, vertical, dist):

        self.dist = dist
        self.horizontal = horizontal
        self.vertical = vertical


    def csvCall( self):
        with open('data_file.csv', mode='a') as employee_file:
            employee_writer = csv.writer(employee_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
            employee_writer.writerow([self.dist, self.horizontal, self.vertical])



#x = CsvBuilder(1,433333333334,71111234567).csvCall()


