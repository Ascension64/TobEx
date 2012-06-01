-- dump.lua

function dump_table(t, name)
  local index, value
  index = nil
  repeat
    index, value = next(t, index)
    if
      not (type(index) == "nil")
    then
      CLUAConsole:DisplayText(name .. "->" .. tostring(index) .. ": " .. tostring(value))
    end

    if
      type(value) == "table"
    then
      dump_table(value, "--subtable")
    end
  until
    index == nil
end

function dump()
  local name, value
  name = nil
  repeat
    name, value = nextvar(name)
    if
      not (type(name) == "nil")
    then
      CLUAConsole:DisplayText(tostring(name) .. "->" .. tostring(value))
    end

    if
      type(value) == "table"
    then
      dump_table(value, "-table")
    end
  until
    name == nil
end
