// stone.c
// 各種原料初始狀態

#include <ansi.h>

inherit ITEM;

int do_yelian();
int do_eat(string stone);

void init()
{
	add_action("do_yelian","yelian");
	add_action("do_eat","eat");
}

void create()
{
	set_name( "補天石", ({ "butian shi","shi","butian"}));
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "塊");
		set("long","這是一塊五彩的石頭，光華閃爍，叫人愛不釋手，久久把玩不願放下。\n"
			+"這塊石頭似乎包含着什麼，你不由想冶煉(yelian)一下，可能會有些什\n"
			+"麼新奇的東西出現\n");
		set("value", 0);
		set("material", "iron");
	}
}

int do_yelian()
{
	object me,stone,new_ob;
 
	me=this_player();
	stone=this_object();

	if( (int)me->query("neili") < 50 )
		return notify_fail("你的內力不夠無法鍛鍊補天石！\n");
	message_vision(HIR "$N盤膝而坐，手託補天石，真氣遊走，開始冶煉補天石。\n" NOR, me);
	me->add("neili",-50);
	switch(random(4) )
	{
		case 0:
			new_ob=new("/d/npc/m_weapon/tan/item/jinmu",1);
			new_ob->move(me);			
			message_vision(HIY "補天石漸漸變形，終於成了一塊紫色的金屬！！\n" NOR, me );
//			destruct(stone);
			stone->move("/u/java/room/readroom");
			break;
		case 1:
			new_ob=new("/d/npc/m_weapon/tan/item/shenmu",1);
			new_ob->move(me);			
			message_vision(HIY "補天石層層剝落，終於成了一塊黑中透紅的木頭！！\n" NOR, me );
//			destruct(stone);
			stone->move("/u/java/room/readroom");
			break;
		case 2:
			new_ob=new("/d/npc/m_weapon/tan/item/hanzhu",1);
			new_ob->move(me);			
			message_vision(HIY "補天石啪的一聲爆響聽起來竟象是竹子燃燒的聲音！！\n" NOR, me );
//			destruct(stone);	
			stone->move("/u/java/room/readroom");
			break;
		default:
			message_vision(HIY "補天石漸漸變軟，終於化做一灘泥水滲入地下，不見了。\n" NOR, me );
//			destruct(stone);
			stone->move("/u/java/room/readroom");
	}
	return 1;
}

int do_eat(string arg)
{
	object me;
	int n;
 
	me=this_player();
	if( !id(arg) )
		return notify_fail("你要喫什麼?\n");
	n=random(3);
	switch(n) {
		case 0:
			message_vision(HIY "$N看來急壞了，拿起補天石就啃，結果當場大牙蹦掉了十二顆!這也算冶煉？真傻！\n" NOR,me);
			me->add("food",200);
			me->add("water",200);
			break;
		default:
			message_vision(HIY "$N看來餓壞了，拿起補天石就啃，結果當場大牙蹦掉了十二顆!\n" NOR,me);
		}
//	destruct(this_object() );
	this_object()->move("/u/java/room/readroom");
	return 1;
}
