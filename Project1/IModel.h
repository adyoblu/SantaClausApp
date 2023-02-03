#pragma once

__interface IModel
{
	virtual void print() = 0;
	virtual void loadFile() = 0;
	virtual int getNr() = 0;
	void Add();
	void Delete();
	void Update();
};