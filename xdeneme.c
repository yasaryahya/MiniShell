/*

void free_2d_array(char **array, int rows)
{
	int i = 0;
    while (i < rows)
	{
        free(array[i]);
		i++;
	}
    free(array);
}

char **export2(t_data *data)
{
    int i = 0;
    int j = 0;
    
    char **new_env = (char **)malloc((data->env_count + data->arg_count + 1) * sizeof(char *));
    if (!new_env)
        ft_error("export/ malloc hatası", 1);
    while (i < data->env_count)
    {
        new_env[i] = strdup(data->envrt[i]);
        if (!new_env[i])
            ft_error("export/ malloc hatası", 1);
        i++;
    }
    while (j + 1 < data->arg_count)
    {
        new_env[i + j] = strdup(data->arg[j+1]);
        if (!new_env[i+j])
            ft_error("export/ malloc hatası", 1);
        j++;
    }
    new_env[i + j] = NULL;
    return new_env;
}

void export(t_data *data)
{
    if (data->arg_count == 1)
        env_print(data, 1);
    else if (data->arg_count >= 2)
    {
        char **merged_env = export2(data);
        //if (data->envrt)
        //    free_2d_array(data->envrt, data->env_count); // Eski çevresel değişkenleri serbest bırakma
        data->envrt = merged_env; // Çevresel değişkenleri yeni merged_env ile güncelleme
    }
    // arg_count 0 ise dönmek yeterli; başka bir işlem gerekmez.
}
*/