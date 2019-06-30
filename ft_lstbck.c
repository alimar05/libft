#include "libft.h"

void	ft_lstbck(t_list **alst, t_list *new)
{
	if (alst != NULL && *alst != NULL)
	{
		ft_lstbck(&(*alst)->next, new);
		if ((*alst)->next == NULL)
			(*alst)->next = new;
	}
}
