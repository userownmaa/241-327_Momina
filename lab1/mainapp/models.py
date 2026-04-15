from django.db import models

# Create your models here.


from django.db import models

class Medicine(models.Model):
    """Модель лекарства для аптеки"""
    
    name = models.CharField(
        max_length=255, 
        verbose_name="Название лекарства"
    )
    price = models.DecimalField(
        max_digits=10, 
        decimal_places=2, 
        verbose_name="Цена"
    )
    quantity_in_stock = models.PositiveIntegerField(
        verbose_name="Количество на складе"
    )
    expiration_date = models.DateField(
        verbose_name="Срок годности"
    )
    manufacturer = models.CharField(
        max_length=255, 
        verbose_name="Производитель"
    )
    requires_prescription = models.BooleanField(
        default=False, 
        verbose_name="По рецепту"
    )
    description = models.TextField(
        blank=True, 
        verbose_name="Описание"
    )

    class Meta:
        verbose_name = "Лекарство"
        verbose_name_plural = "Лекарства"
        ordering = ['-expiration_date'] 

    def __str__(self):
        return f"{self.name} ({self.manufacturer})"