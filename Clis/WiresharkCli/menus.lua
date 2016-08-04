local function dialog_menu()
    local function dialog_func(person,eyes,hair)
        local win = TextWindow.new("The Person");
        win:set(person)
        win:append(" with " .. eyes .." eyes and")
        win:append(" " .. hair .. " hair.");
    end

    new_dialog("Dialog Test",dialog_func,"A Person","Eyes","Hair")
end

register_menu("Lua Dialog Test",dialog_menu,MENU_TOOLS_UNSORTED)