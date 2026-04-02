// tongpai.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_read","see");
}

void create()
{
               set_name("銅牌", ({"tongpai" }));

                set("unit", "面");
                set("long", "這是一面四四方方的銅牌,上面刻着:“千蛛萬毒”四個
大字。\n銅牌背面好象雕着一些細細的花紋，需要仔細看(see)才能勉強看清楚。\n");
                set("value", 0);
              set("no_drop", "這樣東西不能離開你。\n");
              set_weight(200);

        setup();
}

int do_read(string arg)
{
        return notify_fail("                           \n
                                    ^                 \n
                                 @@^ ^     ^          \n
                                  ^ ^ ^   ^ ^ @@@     \n
                               @@@@^ ^ ^ ^ ^ ^        \n
                                ^ ^ ^ ^ ^ ^ ^ ^       \n
                               ^ ^ ^ ^ ^ ^ ^ ^ ^       \n
                              ^ ^ ^ ^O^ ^O^ ^O^ ^       \n
                             ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^       \n
                            ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^      \n
                           ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^    \n
");
}

