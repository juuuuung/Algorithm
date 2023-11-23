import math
def solution(fees, records):
	new_records = []
	total_time = {}
	car_in_out = {}
	car_time = {}
	car_list = []
	answer = []    
	def time_cal(main_hour, main_min, sub_hour, sub_min):
		result_min = sub_min - main_min
		result_hour = sub_hour - main_hour
		if(result_min < 0):
			result_min += 60
			result_hour -= 1
		return (result_hour*60)+result_min
	for i in records: new_records.append(i.split())
	for i in new_records:
		car_number = i[1]
		if i[2] == 'IN':
			car_time[car_number] = i[0]
			car_in_out[car_number] = 1
			total_time[car_number] = 0 if car_number not in total_time else total_time[car_number]
		else:
			total_time[car_number] += time_cal(int(car_time[car_number][:2]),
												int(car_time[car_number][3:5]),
												int(i[0][:2]),
												int(i[0][3:5]))
			car_in_out[car_number] = 0
	for key, val in car_in_out.items():
		car_list.append(key)
		if val:
			total_time[key] += time_cal(int(car_time[key][:2]),
									int(car_time[key][3:5]),
									23,
									59)
		if(total_time[key] <= fees[0]):
			total_time[key] = fees[1]
		else:
			total_time[key] = fees[1] + math.ceil((total_time[key]-fees[0])/fees[2]) * fees[3]
	car_list.sort()
	for i in car_list:
		answer.append(total_time[i])
	return answer