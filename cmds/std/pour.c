// pour.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item, poison;
	object obj, dest/*, *inv, obj2*/;
	int /*i,amount,*/ poisontime;

	if(!arg) return notify_fail("你要下什麼毒？\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("你要往哪裏下毒？\n");

	dest = present(target, me);
	if( !dest) return notify_fail("這裏沒有這樣東西。\n");

	if( !objectp(obj = present(item, me)) )
		return notify_fail("你身上沒有這樣東西。\n");
	if( !obj->query("pour_type"))
		return notify_fail("這東西不能這樣下毒的。\n");

	if( dest->query("liquid/remaining") < 1 )
	{
		tell_object(me, "裏面一點喝的都沒有是不能下毒的。\n");
		return 1;
	}
	message_vision( sprintf("$N將一%s%s偷偷灑進%s。\n",
		obj->query("unit"), obj->name(), dest->name()), me );
	poisontime = (int)(me->query_skill("poison",1)/5) + (int)(me->query_skill("five-poison",1)/5);
	poison = obj->query("pour_type");
	dest->set("liquid/poison", poison);
	dest->set("liquid/poisontime", poisontime);
	destruct(obj);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : pour <毒品名稱> in <某容器>
 
    這個指令可以讓你將某樣毒品放進一個容器，當然，首先你要擁有
這樣物品。容器裏有喝的東西。
HELP
	);
	return 1;
}