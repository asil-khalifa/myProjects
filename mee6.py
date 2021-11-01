from mee6_py_api import API
api = API(706144819063291986)
leaderboard = await api.levels.get_leaderboard_page(0)
print(leaderboard)
