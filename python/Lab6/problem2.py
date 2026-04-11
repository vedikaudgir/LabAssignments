# You are managing a social networking app. Each user can have friends on different platforms (e.g., Facebook, Twitter, LinkedIn). You need to write a function that, given sets of friends from different platforms, finds the mutual friends across all platforms.
#Author - Vedika Udgir

facebook_friends = {"Alice", "Bob", "Charlie"}
twitter_friends = {"Bob", "Charlie", "David"}
linkedin_friends = {"Bob", "Charlie", "Emma"}

mutual_friends = facebook_friends & twitter_friends & linkedin_friends
print(mutual_friends)
