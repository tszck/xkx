// ganchai.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_make","zha");
        add_action("do_make","make");
}

void create()
{
               set_name("乾柴", ({"ganchai" ,"chai"}));

                set("unit", "捆");
                set("long", "這是一小捆燒火用的乾柴。\n");
                set("value", 0);
//            set("no_drop", "這樣東西不能離開你。\n");
              set_weight(500);


        setup();
}

int do_make(string arg)
{
    object me = this_player();
    object ob = this_object();
    if ((ob->query("name"))=="火把")
    return 0;
    if (arg != "火把"& arg !="huoba")
    return 0;
    message_vision ("$N拿起一捆乾柴，三下兩下就紮成了一支火把。\n\n",me);
    this_object()->recreate();
    return 1;
}
void recreate ()
{
               set_name("火把", ({"huo ba","ba"}));

                set("unit", "支");
                set("long", "這是一支照明用的火把。\n");
                set("value", 0);
//            set("no_drop", "這樣東西不能離開你。\n");
              set_weight(300);
        setup();
}

