// walker.c

#include <ansi.h>
inherit NPC;

void create()
{
	mapping name;

	name = NAME_D->man_name();
	set_name(name["name"],({name["id"]}));
        set("gender", "男性");
        set("age", 53 + random(20));
        set("long", @LONG
這是一個拾荒者，看上去老實巴交的。不過聽
説他和官府有交情，最好別去招惹。
LONG);
        set("attitude", "heroism");
        set("str", 35);
        set("int", 15);
        set("con", 19);
        set("dex", 17);

        setup();
        carry_object(CLOTH_DIR"cloth")->wear();
}

