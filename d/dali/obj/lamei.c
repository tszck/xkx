//lamei.c
#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
        set_name(HIW"臘梅"NOR, ({"la mei", "mei"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枝");
                set("long",HIW
"一枝臘梅，清清冷冷地開着，發散着淡雅的芬芳。嚴冬時分，
潔白的花兒經受着寒氣的侵襲，更顯得卓然不羣，純潔嬌媚。
春天，畢竟就要到了。\n" NOR);
                set("value", 80);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N輕輕地把一枝$n插在鬢間。\n");
                set("unequip_msg", "$N輕輕地把$n從頭上摘了下來。\n");
        }     
        setup();
}
