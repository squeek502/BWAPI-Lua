function defaultConstructor()
	local set = BWAPI.UnitTypeset.new()
	assert(#set == 0)
end

function tableConstructor()
	local set = BWAPI.UnitTypeset.new({BWAPI.UnitTypes.Terran_SCV, BWAPI.UnitTypes.Terran_Firebat})
	assert(#set == 2)

	set = BWAPI.UnitTypeset.new({"strings", "ignored"})
	assert(#set == 0)
end

function copyConstructor()
	local set = BWAPI.UnitTypeset.new({BWAPI.UnitTypes.Terran_SCV, BWAPI.UnitTypes.Terran_Firebat})
	assert(#set == 2)

	local copy = BWAPI.UnitTypeset.new(set)
	assert(#copy == 2)
end

function iterator()
	local set = BWAPI.UnitTypeset.new({BWAPI.UnitTypes.Terran_SCV, BWAPI.UnitTypes.Terran_Firebat})

	local scvFound, firebatFound = false, false
	for v in set:iterator() do
		if v == BWAPI.UnitTypes.Terran_SCV then scvFound = true end
		if v == BWAPI.UnitTypes.Terran_Firebat then firebatFound = true end
	end
	assert(scvFound)
	assert(firebatFound)
end

function asTable()
	local set = BWAPI.UnitTypeset.new({BWAPI.UnitTypes.Terran_SCV, BWAPI.UnitTypes.Terran_Firebat})
	local setTable = set:asTable()
	assert(#setTable == 2)

	local scvFound, firebatFound = false, false
	for i,v in ipairs(setTable) do
		if v == BWAPI.UnitTypes.Terran_SCV then scvFound = true end
		if v == BWAPI.UnitTypes.Terran_Firebat then firebatFound = true end
	end
	assert(scvFound)
	assert(firebatFound)
end

function count()
	local set = BWAPI.UnitTypeset.new({BWAPI.UnitTypes.Terran_SCV, BWAPI.UnitTypes.Terran_Firebat})

	assert(set:count(BWAPI.UnitTypes.Terran_SCV) == 1)
	assert(set:count(BWAPI.UnitTypes.Terran_Firebat) == 1)
	assert(set:count(BWAPI.UnitTypes.Terran_Marine) == 0)
end

function size()
	local set = BWAPI.UnitTypeset.new({BWAPI.UnitTypes.Terran_SCV, BWAPI.UnitTypes.Terran_Firebat})
	assert(set:size() == 2)
end

function contains()
	local set = BWAPI.UnitTypeset.new({BWAPI.UnitTypes.Terran_SCV, BWAPI.UnitTypes.Terran_Firebat})

	assert(set:contains(BWAPI.UnitTypes.Terran_SCV) == true)
	assert(set:contains(BWAPI.UnitTypes.Terran_Firebat) == true)
	assert(set:contains(BWAPI.UnitTypes.Terran_Marine) == false)
end

function empty()
	local emptySet = BWAPI.UnitTypeset.new()
	assert(emptySet:empty())

	local set = BWAPI.UnitTypeset.new({BWAPI.UnitTypes.Terran_SCV, BWAPI.UnitTypes.Terran_Firebat})
	assert(not set:empty())
end

function insert()
	local set = BWAPI.UnitTypeset.new()
	set:insert(BWAPI.UnitTypes.Terran_SCV)
	assert(#set == 1)
	set:insert(BWAPI.UnitTypes.Terran_Firebat)
	assert(#set == 2)
end

function erase()
	local set = BWAPI.UnitTypeset.new({BWAPI.UnitTypes.Terran_SCV, BWAPI.UnitTypes.Terran_Firebat})
	assert(#set == 2)
	set:erase(BWAPI.UnitTypes.Terran_SCV)
	assert(#set == 1)
	set:erase(BWAPI.UnitTypes.Terran_Firebat)
	assert(#set == 0)
end

function clear()
	local set = BWAPI.UnitTypeset.new({BWAPI.UnitTypes.Terran_SCV, BWAPI.UnitTypes.Terran_Firebat})
	assert(#set == 2)
	set:clear()
	assert(#set == 0)
end
