#ifndef JL_COMPONENT_HPP
#define JL_COMPONENT_HPP

#include <string>
#include <Lua/lua.hpp>
#include "IdentifierTypes.hpp"

namespace jl
{

	/*
		BaseComponent

		Used primarily to give template component classes a common
		base which provides most of the type specific data.

	*/
	class BaseComponent
	{

	private:

		TypeID m_typeID;
		std::string m_name;

	protected:

		BaseComponent(TypeID typeID, const std::string &name) 
			:
			m_typeID(typeID),
			m_name(name)
		{};

	public:
		virtual ~BaseComponent() {};

		// Functions called by Lua if a LuaComponent is attached
		virtual void onLuaSet(const std::string& valueName, lua_State *context) {};
		virtual int onLuaGet(const std::string& valueName, lua_State *context) {};

		// Cloning function that must be overridden by deriving classes
		virtual BaseComponent* clone()  = 0;


		TypeID getTypeID()  const
		{
			return m_typeID;
		};
		std::string getName() const
		{
			return m_name;
		};

	};

	template<typename TType> class Component : public BaseComponent
	{

	public:

		Component(const std::string &name = "") 
			:
			BaseComponent(TypeIdGrabber::getUniqueTypeID<TType>(), name)
		{};
		virtual ~Component() {};

		// Override cloning
		virtual BaseComponent* clone() 
		{
			// CRTP - Curiously Recurring Template Pattern
			return new TType(static_cast<TType const&>(*this));
		};
	};

	/*
		Component

		Base class for all types of sub components which is what makes
		up entities.

	*/
	/*class Component
	{
	private:

		friend class Entity;
		TypeID m_typeID;

	public:

		Component() 
			:
			m_typeID(0)
		{};
		virtual ~Component() {};


		TypeID getTypeID()  const
		{
			return m_typeID;
		};
	};*/

};

#endif