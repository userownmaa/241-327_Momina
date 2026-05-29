FROM python:3.13-slim

ENV PYTHONDONTWRITEBYTECODE=1
ENV PYTHONUNBUFFERED=1

WORKDIR /backend

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY . .

# Сбор статики при сборке образа
RUN python manage.py collectstatic --noinput

# Команда по умолчанию (переопределяется в compose)
CMD ["gunicorn", "lab1.wsgi:application", "--bind", "0.0.0.0:8000"]