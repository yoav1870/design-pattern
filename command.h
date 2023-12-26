#pragma once

#include "myView.h"
#include "myModel.h"
#include "myController.h"

class command
{
public:
    virtual void execute(const std::string& param) = 0;
};

class dir : public command
{
public:
    virtual void execute(const std::string& param);
};
class compress : public command
{
public:
    virtual void execute(const std::string& param);
};
class generate_maze : public command
{
public:

    virtual void execute(const std::string& param);
};
class display : public command
{
public:

    virtual void execute(const std::string& param);
};
class save_maze : public command
{
public:

    virtual void execute(const std::string& param);
};
class load_maze : public command
{
public:

    virtual void execute(const std::string& param);
};
class maze_size : public command
{
public:

    virtual void execute(const std::string& param);
};
class file_size : public command
{
public:

    virtual void execute(const std::string& param);
};
class load_compress : public command
{
public:

    virtual void execute(const std::string& param);
};
class solve : public command
{
public:

    virtual void execute(const std::string& param);
};
class display_solution : public command
{
public:

    virtual void execute(const std::string& param);
};
class Exit : public command
{
public:
    virtual void execute(const std::string& param);
};