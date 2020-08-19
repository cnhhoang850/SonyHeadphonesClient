#pragma once

#include <stdexcept>
#include <string>

//An exception that should be shown in the UI, and that doesn't make any state invalid.
class RecoverableException : public std::runtime_error {
public:
	//I: what - This string WILL BE SHOWN TO THE USER.
	RecoverableException(const std::string& what) : std::runtime_error(what) {}
};

//This exception will make the connection disconnect, as well as show the error to the user.
class DisconnectingException : public RecoverableException {
public:
	DisconnectingException(const std::string& what) : RecoverableException(what) {}
};