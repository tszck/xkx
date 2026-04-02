// id.c
// Modified by Spacenet@FXLT

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, j;
	object /*obj,*/ *inv, *inv1;
//	string *id;
	string str;

	if( !arg ) {
		inv = all_inventory(me);
		if( !sizeof(inv) )
			return notify_fail("你身上沒有任何東西。\n");
		for (i = 0;i < sizeof(inv);i ++)
			if (!arrayp(inv1)) 
				inv1 = ({inv[i]});
			else {
				for (j = 0;j < sizeof(inv1);j ++)
					if (inv[i]->short(1) == inv1[j]->short(1))
						break;
				if (j == sizeof(inv1))
					inv1 += ({inv[i]});
			}
			
		write( "你(你)身上攜帶物品的別稱如下(右方) :\n");
		for(i = 0; i < sizeof(inv1); i ++) {
			if( !me->visible(inv1[i]) ) continue;
			printf("%-20s = %s\n", inv1[i]->name(),
				implode(inv1[i]->parse_command_id_list(), ", ") );
		}
		return 1;
	}

	if( arg=="here" ) {
		inv = all_inventory(environment(me));
		if( !sizeof(inv) )
			return notify_fail("這裏沒有任何東西。\n");
		write( "在這個房間中, 生物及物品的(英文)名稱如下 :\n");
		for(i=0; i<sizeof(inv); i++) {
			if( !me->visible(inv[i]) ) continue;
			str = implode(inv[i]->parse_command_id_list(), ", ");
			if (inv[i]->query_temp("pretend") && 
				arrayp(inv[i]->query_temp("apply/pid")))
			str = implode(inv[i]->query_temp("apply/pid"), ", ");
			printf("%-20s = %s\n", inv[i]->name(),str );
		}
		return 1;
	}
}
int help(object me)
{
write(@HELP
指令格式 : id [here]
 
    這個指令可以讓你知道物品的英文名稱及名字。只打 id 會顯示
你身上所攜帶物品的名稱。'id here' 則顯示所有跟你在同一個環境
裏的物件名稱。
 
HELP
	);
	return 1;
}
 
