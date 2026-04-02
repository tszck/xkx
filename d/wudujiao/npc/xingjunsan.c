// xingjunsan.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat","eat");
}

void create()
{
        set_name("諸葛行軍散", ({"xingjun san"}));

        set("unit", "包");
        set("long", "這是一包預防瘴氣的藥散，帶在身上可以預防瘴氣。\n");
        set("value", 0);
//        set("no_drop", "這樣東西不能離開你。\n");
        set_weight(200);

        setup();
}
int do_eat(string arg)
{
        if (arg == "xingjun san")
                message_vision ("這種東西只能帶在身上，不能喫啊。\n",this_player());
        return 1;
}

