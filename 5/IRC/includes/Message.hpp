#pragma once

#include <iostream>
#include <cstdarg>
#include <vector>

#define WAITING() (":localhost NOTICE * :*** Looking up your hostname...\r\n")

#define ERR_UNKNOWNCOMMAND(nickname, command) (":localhost 421 " + nickname + " " + command + " :Unknown command\r\n")
// NICK
#define ERR_NONICKNAMEGIVEN(nickname) (":localhost 431 " + nickname + " :No nickname given\r\n")
#define ERR_ERRONEUSNICKNAME(nickname, command) (":localhost 432 " + nickname + " " + command + " :Erroneus nickname\r\n")
#define ERR_NICKNAMEINUSE(nickname, command) (":localhost 433 " + nickname + " " + command + " :Nickname is already in use.\r\n")
#define RPL_NICK(oldnick, username, ipaddr, newnick) (":" + oldnick + "!" + username + "@"+ ipaddr + " NICK :" + newnick + "\r\n")
// Quit
#define ERR_CLOSE(username, ipaddr, msg) ("ERROR :Closing link: (" + username + "@" + ipaddr + ") [" + msg + "]\r\n")
// PASS, USER
#define ERR_NEEDMOREPARAMS(nickname, command) (":localhost 461 " + nickname + " " + command + " :Not enough parameters\r\n")
#define ERR_ALREADYREGISTRED(nickname) (":localhost 462 " + nickname + " : You may not reregister\r\n")
#define ERR_ERRONEUSUSER(nickname) (":localhost 468 " + nickname + " :Your username is not valid\r\n")

//PRIVMSG
#define ERR_NORECIPIENT(nickname, command) (":localhost 411 " + nickname + " :No recipient given (" + command + ")\r\n")
#define ERR_NOTEXTTOSEND(nickname) (":localhost 412 " + nickname + " :No text to send\r\n")
#define ERR_CANNOTSENDTOCHAN(nickname, channel) (":localhost 404 " + nickname + " " + channel + " :Cannot send to channel\r\n")
#define ERR_NOTOPLEVEL(nickname, mask) (":localhost 413 " + nickname + "<mask> :No toplevel domain specified\r\n")
#define ERR_WILDTOPLEVEL(nickname, mask) (":localhost 414 " + nickname + "<mask> :Wildcard in toplevel domain\r\n")
#define ERR_TOOMANYTARGETS(nickname, target) (":localhost 407 " + nickname +"<target> :Duplicate recipients. No message delivered\r\n")
#define ERR_NOSUCHNICK(nickname, nick) (":localhost 401 " + nickname + " " + nick + " :No such nick/channel\r\n")
#define RPL_AWAY(nickname, username, ipaddr, name, message) (":" + nickname + "!" + username + "@" + ipaddr + " PRIVMSG " + nickname + " :" + message + "\r\n")
#define RPL_AWAYCH(nickname, username, ipaddr, channel, message) (":" + nickname + "!" + username + "@" + ipaddr + " PRIVMSG " + channel + " :" + message + "\r\n")

// JOIN
#define ERR_CHANNELISFULL(nickname, channel) (":localhost 471 " + nickname + " " + channel + " :Cannot join channel (l)\r\n")
#define ERR_INVITEONLYCHAN(nickname, channel) (":localhost 473 " + nickname + " " + channel + " :Cannot join channel (i)\r\n")
#define ERR_BANNEDFROMCHAN(nickname, channel) (":localhost 474 " + nickname + " " + channel + " :Cannot join channel (b)\r\n")
#define ERR_BADCHANNELKEY(nickname, channel) (":localhost 475 " + nickname + " " + channel + " :Cannot join channel (incorrect channel key)\r\n")
#define ERR_NOSUCHCHANNEL(nickname, channel) (":localhost 403 " + nickname + " " + channel + " :No such channel\r\n")
#define ERR_TOOMANYCHANNELS(nickname, channel) (":localhost 405 " + nickname + " " + channel + " :you have joined too many channels\r\n")
#define RPL_SETTOPIC(nickname, username, ipaddr, channel, topic) (":" + nickname + "!" + username + "@" + ipaddr + " TOPIC " + channel + " :" + topic + "\r\n")
std::string RPL_NAMREPLY(const std::string &nickname, const std::string &type, const std::string &channel, const std::vector<std::string>& nick);

#define RPL_ENDOFNAMES(nickname, channel) (":localhost 366 " + nickname + " " + channel + " :End of /NAMES list.\r\n")
#define ERR_USERNOTINCHANNEL(nickname, user, channel) (":localhost 441 " + nickname + " " + user + " " + channel + " :They aren't on that channel\r\n")
#define	RPL_JOIN(nickname, username, ipaddr, channel) (":" + nickname + "!" + username + "@" + ipaddr + " JOIN :" + channel + "\r\n")
#define RPL_KICK(nickname, username, ipaddr, channel, user, msg) (":" + nickname + "!" + username + "@" + ipaddr + " KICK " + channel + " " + user + " :" + msg + "\r\n")
#define RPL_MODE(nickname, username, ipaddr, channel, msg) (":" + nickname + "!" + username + "@" + ipaddr + " MODE " + channel + " " + msg + "\r\n")
// PING
# define MSG_PONG(cmd) (":localhost PONG localhost :" + cmd + "\r\n")
// PART :asd!a@127.0.0.1 PART :#ch1
#define RPL_PART(nickname, username, ipaddr, channel) (":" + nickname + "!" + username + "@" + ipaddr + " PART :" + channel + "\r\n")

// INVITE
#define ERR_NOTREGISTERED(nick) (":" + nick + " :You have not registered\r\n")
#define ERR_USERONCHANNEL(nick, invitee, channel) (":localhost 443 " + nick + " " + invitee + " " + channel + " :is already on channel\r\n")
#define RPL_INVITING(nick, invitee, channel) (":localhost 341 " + nick + " " + invitee + " :" + channel + "\r\n")
#define RPL_AWAY_INVITE(nick, user, invitee, ipaddr, channel) (":" + nick + "!" + user + "@" + ipaddr + " INVITE " + invitee + " :" + channel + "\r\n")
#define ERR_INVALIDDURATION(nick) (":localhost NOTICE " + nick + " :*** Invalid duration for invite\r\n")
#define ERR_ALREADYONCHANNEL(nick, invitee, channel) (":localhost 443 " + nick + " " + invitee + " " + channel + " :is already on channel\r\n")
#define RPL_INVITELIST(nick, channel) (":localhost 346 " + nick + " :" + channel + "\r\n")
#define RPL_INVITEEND(nick) (":localhost 347 " + nick + " :End of INVITE list\r\n")

// TOPIC
#define ERR_NOTONCHANNEL(nickname, channel) (":localhost 442 " + nickname + " " + channel + " :You're not on that channel\r\n")
#define RPL_NOTOPIC(nickname, channel) (":localhost 331 " + nickname + " " + channel + " :No topic is set.\r\n")
#define RPL_TOPIC(nickname, channel, topic) (":localhost 332 " + nickname + " " + channel + " :" + topic + "\r\n")
#define	RPL_TIMETOPIC(nickname, channel, setnick, setuser, ipaddr, settime) (":localhost 333 " + nickname + " " + channel + " " + setnick + "!" + setuser + "@" + ipaddr + " :" + settime + "\r\n")
#define ERR_CHANOPRIVSNEEDED(nickname, channel) (":localhost 482 " + nickname + " " + channel + " :You're not channel operator\r\n")

// MODE
#define RPL_CHANNELMODEIS(nick, channel, params) (":localhost 324 " + nick + " " + channel + " :+" + params + "\r\n")
#define RPL_CHANNELTIME(nick, channel, channeltime) (":localhost 329 " + nick + " " + channel + " :" + channeltime + "\r\n")
#define ERR_UNKNOWNMODE(nick, c) (":localhost 472 "+ nick + " " + c + " :is an unknown mode character\r\n") 
#define ERR_NOPARAMETER(nickname, channel, flag, mode, parameter) (":localhost 696 " + nickname + " " + channel + " " + flag + " * :You must specify a parameter for the " + mode + " mode. Syntax:" + parameter + "\r\n")
#define ERR_CHANOPMODE(nickname, channel, mode) (":localhost 482 " + nickname + " " + channel + " :You must have channel op access or above to set channel mode " + mode + "\r\n")

//BOT
#define ERR_BOTSTART() ("BOT NEED START\r\n")

// PASS, NICK, USER 입력후 서버 접속 메세지
#define MSG_WELCOME(Time, nickname) (":localhost 001 " + nickname + " : Welcome to the Localnet IRC Network\r\n" + \
						":localhost 002 " + nickname + " : Your host is localhost!\r\n" + \
						":localhost 003 " + nickname + " :This server was created " + Time + "\r\n" + \
						":localhost 004 " + nickname + " :localhost IRC_SERVER none iklot :klo\r\n" +/*<version> <user_modes> <channel_modes> :<channel_modes_with_params>*/\
						":localhost 375 " + nickname + " :localhost message of the day.\r\n" + \
						":localhost 372 " + nickname + " :- **************************************************\r\n" + \
						":localhost 372 " + nickname + " :- *             H    E    L    L    O              *\r\n" + \
						":localhost 372 " + nickname + " :- *  This is a irc subject server. Please don`t    *\r\n" + \
						":localhost 372 " + nickname + " :- *  contact the admin of the server for any       *\r\n" + \
						":localhost 372 " + nickname + " :- *  questions or issues.                          *\r\n" + \
						":localhost 372 " + nickname + " :- **************************************************\r\n" + \
						":localhost 376 " + nickname + " :End of message of the day.\r\n")

void		sendMsg(std::string msg, int fd);
