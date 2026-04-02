// mamian.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIY "馬面" NOR, ({ "ma mian" }) );
        set("nickname",CYN "妖怪" NOR);
        set("long",GRN @LONG
一個似人非人，似畜非畜的妖怪，人身馬面，似笑似哭，尖牙齜露...
LONG NOR);
	set("max_jing", 10000);
	set("max_qi", 10000);
        set("age",1000000);
	set("combat_exp",1000000);
        
	setup();
}
int is_ghost()
{  
      return 1;
}
